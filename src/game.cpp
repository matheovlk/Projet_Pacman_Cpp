
#include "game.hpp"
#include "score.hpp"

void Game::init(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites)
{
	std::array<std::string, MAP_HEIGHT> map_sketch = {
	"wwwwwwwwwwwwwwwwwwwww",
	"w.........w.........w",
	"w.www.www.w.www.www.w",
	"wowww.www.w.www.wwwow",
	"w.www.www.w.www.www.w",
	"w...................w",
	"w.www.w.wwwww.w.www.w",
	"w.www.w.wwwww.w.www.w",
	"w.....w...w...w.....w",
	"wwwww.www w www.wwwww",
	"wwwww.w   1   w.wwwww",
	"wwwww.w wwDww w.wwwww",
	"wwwww.w w234w w.wwwww",
	"     .  w   w  .     ",
	"wwwww.w wwwww w.wwwww",
	"wwwww.w       w.wwwww",
	"wwwww.w wwwww w.wwwww",
	"wwwww.w wwwww w.wwwww",
	"w.........w.........w",
	"w.www.www.w.www.www.w",
	"wo..w.....P.....w..ow",
	"www.w.w.wwwww.w.w.www",
	"www.w.w.wwwww.w.w.www",
	"w.....w...w...w.....w",
	"w.wwwwwww.w.wwwwwww.w",
	"w...................w",
	"wwwwwwwwwwwwwwwwwwwww",
	};	

	SDL_Event event;
	
	bool quit = false;

	Pacman pacman{sprites, win_surf};

	std::vector<std::unique_ptr<Ghost>> ghosts; //= {Blinky{sprites, win_surf},Blinky{sprites, win_surf},Blinky{sprites, win_surf},Blinky{sprites, win_surf}};
	auto blinky = std::make_unique<Blinky>(sprites, win_surf);
	auto inky = std::make_unique<Inky>(sprites, win_surf);
	auto pinky = std::make_unique<Pinky>(sprites, win_surf);
	auto clyde = std::make_unique<Clyde>(sprites, win_surf);

	// Le std::move dans le code précédent sert à indiquer que le pointeur unique red_ghost peut être déplacé vers l’élément du vecteur,
	// c’est-à-dire que la propriété du pointeur est transférée du red_ghost au vecteur.
	// Cela permet d’éviter de copier le pointeur unique, ce qui n’est pas possible car il ne peut y avoir qu’un seul propriétaire du pointeur.
    ghosts.push_back(std::move (blinky));
	ghosts.push_back(std::move (inky));
    ghosts.push_back(std::move (pinky));
    ghosts.push_back(std::move (clyde));

	Board board{map_sketch, pacman, ghosts, sprites, win_surf};

	Drawable map{sprites, win_surf, map_sprite_loc, MAP_SPRITE_SCALE, false, OFFSET};

	map.draw(0, 0);

	Score score{};



	Word high_score_word{sprites, win_surf};
	high_score_word.set_word("HIGH SCORE");
	high_score_word.draw(HIGH_SCORE_BASIC_OFFSET, 10);

	Word score_sprite{sprites, win_surf};
	Word high_score_sprite{sprites, win_surf};

	board.draw();
	Board_cells& board_cells = board.get_board_cells();

	for (auto& ghost : ghosts)
	{
		ghost->move(board_cells);
		ghost->draw(update_anim);
	}

	pacman.draw(update_anim);
	SDL_UpdateWindowSurface(pWindow);
	// SDL_Delay(2000);


	while (!quit)
	{
		Uint64 start = SDL_GetPerformanceCounter();

		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			default: break;
			}
		}
		update_anim = get_update_animation_index();

		// Gestion du clavier     
		
		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		if (keys[SDL_SCANCODE_ESCAPE])
			quit = true;
		if (keys[SDL_SCANCODE_LEFT])
		{
			pacman.set_direction(Direction::LEFT, board_cells);
		}	
		if (keys[SDL_SCANCODE_RETURN])
		{
			board.sketch_to_board(map_sketch, pacman, ghosts, sprites, win_surf);


			map.draw(0, 0);
			board.draw();
			for (auto& ghost : ghosts)
			{
				ghost->draw(update_anim);
			}
			pacman.draw(update_anim);
			SDL_UpdateWindowSurface(pWindow); 
			SDL_Delay(2000);

		}
		if (keys[SDL_SCANCODE_RIGHT])
		{
			pacman.set_direction(Direction::RIGHT, board_cells);
		}
		if (keys[SDL_SCANCODE_UP])
		{
			pacman.set_direction(Direction::UP, board_cells);
		}
		if (keys[SDL_SCANCODE_DOWN])
		{
			pacman.set_direction(Direction::DOWN, board_cells);
		}

		int sc = score.get_score();
		score_sprite.set_word(sc);
		// We want the last number of the score to be always on the same place.
		// When the score length increments (90 to 100 for ex), the zero stays at the same place
		// The bigger the score is, the smaller the offset is
		score_sprite.draw(SCORE_BASIC_OFFSET+LENGTH_SCORE-SCALED_CHARACTER*(std::to_string(sc).length()), 30);

		int high_sc = score.get_high_score();
		score_sprite.set_word(high_sc);
		// Same logic as the score
		score_sprite.draw(HIGH_SCORE_BASIC_OFFSET+LENGTH_SCORE-SCALED_CHARACTER*(std::to_string(high_sc).length()-4), 30);
		
		map.draw(0, 0);

		board.draw();

		pacman.move(board_cells);

		board.interract(pacman, score);

		// std:cout << 
		for (auto& ghost : ghosts)
		{
			ghost->move(board_cells);
			ghost->draw(update_anim);
		}

		pacman.draw(update_anim);

		// AFFICHAGE
		SDL_UpdateWindowSurface(pWindow); 

		//30 FPS
		Uint64 end = SDL_GetPerformanceCounter();
		float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(std::max(floor(10.0f / GAME_SPEED - elapsedMS), 0.0f));
	}
}

bool Game::get_update_animation_index()
{
	game_animation_index++;
	if (!(game_animation_index = game_animation_index % 10))
		return true;
	return false;
}