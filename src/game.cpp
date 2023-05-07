
#include "game.hpp"

Game::Game(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites)
{
	this->pWindow = pWindow;
	this->win_surf = win_surf;
	this->sprites = sprites;
}

// Init the game once
void Game::init()
{

	std::ifstream file("assets/map.txt");
	for (int i = 0; i < MAP_HEIGHT; i++)
    {
        std::getline(file, this->map_sketch[i]);
    }

    // Fermer le fichier
    file.close();

	SDL_Event event;

	this->pacman = Pacman{this->sprites, this->win_surf};

	auto blinky = std::make_unique<Blinky>(this->sprites, this->win_surf);
	auto inky = std::make_unique<Inky>(this->sprites, this->win_surf);
	auto pinky = std::make_unique<Pinky>(this->sprites, this->win_surf);
	auto clyde = std::make_unique<Clyde>(this->sprites, this->win_surf);

	// avoid copy on unique_ptr
    this->ghosts.push_back(std::move (blinky));
	this->ghosts.push_back(std::move (inky));
    this->ghosts.push_back(std::move (pinky));
    this->ghosts.push_back(std::move (clyde));

	this->board = Board{};

	this->map = Drawable{this->sprites, this->win_surf, map_sprite_loc, MAP_SPRITE_SCALE, false, OFFSET};

	this->lives = Lives{this->sprites, this->win_surf};

	this->score = Score{this->sprites, this->win_surf};

	this->score.print_basic_scores();

	while (!this->quit)
	{
		this->start_game();
	}
}

// Game start & Game over restart
void Game::start_game()
{
	while (!this->quit)
	{
		this->game_lost = false;

		this->lives.restore_lives();
		this->score.reset_score();
		this->new_life();
	}
}

// Restart pacman new life
void Game::new_life()
{
	while (!this->quit && !this->game_lost)
	{
		this->life_lost = false;

		this->board.reset_board(this->map_sketch, pacman, ghosts, this->sprites, this->win_surf);
		Word ready{this->sprites, this->win_surf};
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

		this->loop();
	}
}

void Game::loop()
{
	while (!this->quit && !this->life_lost && !this->game_lost)
	{
		// Timer start for frame duration | auto bc we dont care about type
		auto start = SDL_GetPerformanceCounter();

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

		// quit all loops
		if (keys[SDL_SCANCODE_ESCAPE])
		{
			this->quit = true;
		}
		if (keys[SDL_SCANCODE_RETURN])
		{	
			//quit partie loop
			this->game_lost = true;
		}
		
        // Use a map to associate keys with directions
        std::map<SDL_Scancode, Direction> key_to_dir {
            {SDL_SCANCODE_LEFT, Direction::LEFT},
            {SDL_SCANCODE_RIGHT, Direction::RIGHT},
            {SDL_SCANCODE_UP, Direction::UP},
            {SDL_SCANCODE_DOWN, Direction::DOWN}
        };
        
        for (const auto& [key, dir] : key_to_dir) {
            if (keys[key]) {
                this->pacman.set_direction(dir, board_cells);
            }
        }

		// Loop actions
		this->pacman.move(board_cells);

		this->board.interract(pacman, score);

        auto nb_eaten_gum = board.get_eaten_gum_nb();
        const int max_gum_nb = 188;
        if (nb_eaten_gum == max_gum_nb)
        {
            this->life_lost = true;
        }

        // Lambda function to encapsulate the  checking collisions and lives logic
        auto check_game_state = [this]() {
            if (this->board.check_collide_ghost(pacman, ghosts))
            {
                this->lives.remove_life();
                this->life_lost = true;
                if (this->lives.game_over())
                    this->game_lost = true;
            }
        };
        
        check_game_state();

        //Draw everything
        this->score.print_scores();


        this->map.draw(0, 0);
        
        this->board.draw();

        for (const auto& ghost : ghosts)
        {
            ghost->move(board_cells, nb_eaten_gum);
            ghost->draw(update_anim);
        }


        this->pacman.draw(update_anim);

        this->lives.draw_lives();

        // Display frame
        SDL_UpdateWindowSurface(this->pWindow); 
		//200 FPS !!
		Uint64 end = SDL_GetPerformanceCounter();
		float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(std::max(floor(5.0f / GAME_SPEED - elapsedMS), 0.0f));
	}
}

bool Game::get_update_animation_index()
{
	game_animation_index++;
	if (!(game_animation_index = game_animation_index % 20))
		return true;
	return false;
}
