#pragma once

#include "constants.hpp"

#include <SDL2/SDL.h> 

class Drawable
{
    public:

        Drawable(SDL_Surface* sprites, SDL_Surface* win_surf, const SDL_Rect& sprite_coord, unsigned char scale = BASIC_SPRITE_SCALE, bool transparent = true, const char offset = OFFSET);

        Drawable(SDL_Surface* sprites, SDL_Surface* win_surf, const char offset = OFFSET);
        
        void draw(int x, int y);

    protected:
        Drawable(){};
        SDL_Rect sprite_coord_;
        unsigned char scale_ = BASIC_SPRITE_SCALE;
        bool transparent_;
        SDL_Surface* sprites_ = nullptr;
        SDL_Surface* win_surf_ = nullptr;
        int offset_;
};