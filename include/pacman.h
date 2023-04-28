#pragma once

#include "movable.h"
#include "constants.h"

class Pacman: public Movable
{
    public:
        Pacman(SDL_Surface* sprites,SDL_Surface* win_surf)
        {
            sprites_ = sprites;
            win_surf_ = win_surf;
            sprite_coord_ = SDL_Rect {PACMAN_SPRITE_X, PACMAN_SPRITE_Y, PACMAN_SPRITE_W, PACMAN_SPRITE_H};
            scale_ = BASIC_SPRITE_SCALE;
            transparent_ = true;
        }

        void draw();

        void go_up();
        void go_down();
        void go_left();
        void go_right();

};