
#include "game.hpp"

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
	"wwwww.w   R   w.wwwww",
	"wwwww.w wwwww w.wwwww",
	"wwwww.w wwwww w.wwwww",
	"     .  wwwww  .     ",
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

	Ghost ghost{sprites, win_surf};

	Board board{map_sketch, pacman, ghost, sprites, win_surf};

	Drawable map{sprites, win_surf, map_sprite_loc, MAP_SPRITE_SCALE, false};


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

		Board_cells& board_cells = board.get_board_cells();
		
		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		if (keys[SDL_SCANCODE_ESCAPE])
			quit = true;
		if (keys[SDL_SCANCODE_LEFT])
		{
			pacman.set_direction(Direction::LEFT, board_cells);
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
		
		map.draw(0, 0);

		board.draw();

		pacman.move(board_cells);
		ghost.move(board_cells);

		board.interract(pacman);

		pacman.draw(update_anim);
		ghost.draw(update_anim);

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