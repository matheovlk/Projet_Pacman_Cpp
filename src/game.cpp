
#include "game.hpp"

// Init the game once
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
	"wwwww.w   F   w.wwwww",
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

	this->pacman = Pacman{sprites, win_surf};

	auto blinky = std::make_unique<Blinky>(sprites, win_surf);
	auto inky = std::make_unique<Inky>(sprites, win_surf);
	auto pinky = std::make_unique<Pinky>(sprites, win_surf);
	auto clyde = std::make_unique<Clyde>(sprites, win_surf);

	// avoid copy on unique_ptr
    this->ghosts.push_back(std::move (blinky));
	this->ghosts.push_back(std::move (inky));
    this->ghosts.push_back(std::move (pinky));
    this->ghosts.push_back(std::move (clyde));

	this->board = Board{};

	this->map = Drawable{sprites, win_surf, map_sprite_loc, MAP_SPRITE_SCALE, false, OFFSET};

	this->lives = Lives{sprites, win_surf};

	this->score = Score{sprites, win_surf};

	this->score.print_basic_scores();

	while (!this->quit)
	{
		this->start_game(pWindow, win_surf, sprites, map_sketch);
	}
}

// Game start & Game over restart
void Game::start_game(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites, std::array<std::string, MAP_HEIGHT> map_sketch)
{
	while (!this->quit)
	{
		this->game_lost = false;

		this->lives.restore_lives();
		this->score.reset_score();
		this->new_life(pWindow, win_surf, sprites, map_sketch);
	}
}

// Restart pacman new life
void Game::new_life(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites, std::array<std::string, MAP_HEIGHT> map_sketch)
{
	while (!this->quit && !this->game_lost)
	{
		this->life_lost = false;

		this->board.reset_board(map_sketch, pacman, ghosts, sprites, win_surf);
		Word ready{sprites, win_surf};
		ready.set_word("READY!");

		//Reset position of everything
		this->board_cells = &(board.get_board_cells());

		// Draw everything 
		this->map.draw(0, 0);
		this->board.draw();
		ready.draw(290, 564);
		pacman.draw(update_anim);

		//Draw every ghost
		for (auto& ghost : ghosts)
		{
			ghost->draw(update_anim);
		}

		//Draw to window
		SDL_UpdateWindowSurface(pWindow);

		//Add delay for ready to stay
		SDL_Delay(2000);

		this->loop(pWindow);
	}
}

void Game::loop(SDL_Window* pWindow)
{
	while (!this->quit && !this->life_lost && !this->game_lost)
	{
		// Timer start for frame duration
		Uint64 start = SDL_GetPerformanceCounter();

		SDL_Event event;
		
		// Exit sdl on quit
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

		// Clock for animated Drawables
		update_anim = get_update_animation_index();

		// Gestion du clavier     
		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		if (keys[SDL_SCANCODE_ESCAPE])
		{
			this->quit = true;
		}
		if (keys[SDL_SCANCODE_RETURN])
		{
			this->game_lost = true;
		}
		if (keys[SDL_SCANCODE_LEFT])
		{
			this->pacman.set_direction(Direction::LEFT, board_cells);
		}	
		if (keys[SDL_SCANCODE_RIGHT])
		{
			this->pacman.set_direction(Direction::RIGHT, board_cells);
		}
		if (keys[SDL_SCANCODE_UP])
		{
			this->pacman.set_direction(Direction::UP, board_cells);
		}
		if (keys[SDL_SCANCODE_DOWN])
		{
			this->pacman.set_direction(Direction::DOWN, board_cells);
		}

		this->score.print_scores();

		this->map.draw(0, 0);

		this->board.draw();

		this->pacman.move(board_cells);

		// if (this->board.check_collide_ghost(pacman, ghosts))
		// {
		// 	this->lives.remove_life();
		// 	this->life_lost = true;
		// 	if (this->lives.game_over())
		// 		this->game_lost = true;

		// }
		this->board.interract(pacman, score);

		this->nb_eaten_gum = board.get_eaten_gum_nb();

		if (nb_eaten_gum == 188)
		{
			this->life_lost = true;
		}

		for (auto& ghost : ghosts)
		{
			ghost->move(board_cells, nb_eaten_gum);
			ghost->draw(update_anim);
		}

		this->pacman.draw(update_anim);
		this->lives.draw_lives();

		// AFFICHAGE
		SDL_UpdateWindowSurface(pWindow); 

		//200 FPS !!
		Uint64 end = SDL_GetPerformanceCounter();
		float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(std::max(floor(5.0f / GAME_SPEED - elapsedMS), 0.0f));
	}
}

bool Game::get_update_animation_index()
{
	game_animation_index++;
	if (!(game_animation_index = game_animation_index % 10))
		return true;
	return false;
}
