#pragma once

#include "constants.h"

#include <SDL2/SDL.h> 

class Drawable
{
    public:

        Drawable(SDL_Surface* sprites,SDL_Surface* win_surf, SDL_Rect sprite_coord, unsigned char scale = BASIC_SPRITE_SCALE, bool transparent = true)
        {
            sprites_ = sprites;
            win_surf_ = win_surf;
            sprite_coord_ = sprite_coord;
            scale_ = scale;
            transparent_ = transparent;
        }

        void draw(int x, int y);

    protected:
        Drawable(){};
        SDL_Rect sprite_coord_;
        unsigned char scale_;
        bool transparent_;
        SDL_Surface* sprites_ = nullptr;
        SDL_Surface* win_surf_ = nullptr;
};