#pragma once

#include <array>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <algorithm>

#include "constants.hpp"

#include "drawable.hpp"
#include "board.hpp"
#include "pacman.hpp"
#include "ghost.hpp"
#include "cell.hpp"

class Game
{
    public:
        
        Game(){};

        void init(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites);

    private:
        bool update_anim = false;
        bool get_update_animation_index();
        unsigned char game_animation_index = 0;
        SDL_Rect map_sprite_loc = { MAP_SPRITE_X ,MAP_SPRITE_Y, MAP_SPRITE_W, MAP_SPRITE_H }; // x,y, w,h (0,0) en haut a gauche

};