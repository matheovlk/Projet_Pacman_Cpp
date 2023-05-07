#pragma once

#include <array>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <algorithm>

#include "constants.hpp"

#include "drawable.hpp"
#include "board.hpp"
#include "pacman.hpp"
#include "inky.hpp"
#include "pinky.hpp"
#include "blinky.hpp"
#include "clyde.hpp"
#include "cell.hpp"
#include "word.hpp"
#include "score.hpp"
#include "lives.hpp"

class Game
{
    public:
        
        Game(){};

        void init(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites);
        // void game_handler(SDL_Window*);
        void start_game(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites, std::array<std::string, MAP_HEIGHT> map_sketch);
        void new_life(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites, std::array<std::string, MAP_HEIGHT> map_sketch);
        void loop(SDL_Window*);


    private:
        bool update_anim = false;
        bool get_update_animation_index();
        unsigned char game_animation_index = 0;
        Drawable map{};
        SDL_Rect map_sprite_loc = { MAP_SPRITE_X ,MAP_SPRITE_Y, MAP_SPRITE_W, MAP_SPRITE_H }; // x,y, w,h (0,0) en haut a gauche
        Pacman pacman{};
        Board board{};
	    std::vector<std::unique_ptr<Ghost>> ghosts;
        bool quit = false;
        bool game_lost = false;
        bool life_lost = false;
        Score score{};
        Lives lives{};
        int nb_eaten_gum;
        Board_cells* board_cells;

};