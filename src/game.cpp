#include "constants.hpp"
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
	"wwwww.w       w.wwwww",
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

	Board board{map_sketch, pacman, sprites, win_surf};

	Drawable map{sprites, win_surf, map_sprite_loc, MAP_SPRITE_SCALE, false, OFFSET};

	// SDL_Rect zero_sprite_loc = { 4, 53, 7, 7 };
	// Drawable zero{sprites, win_surf, zero_sprite_loc, CHAR_SPRITE_SCALE, true};
	// first.draw(0, 0);
	// second.draw(15, 0);
	// third.draw(30, 0);
	// fourth.draw(45, 0);
	// fifth.draw(60, 0);
	// sixth.draw(75, 0);

	Score score{sprites, win_surf};

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

		board.interract(pacman, score);

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