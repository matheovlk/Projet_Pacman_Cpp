#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include <SDL2/SDL.h> 

class Drawable
{
    public:
        Drawable(SDL_Surface* sprites,SDL_Surface* win_surf, SDL_Rect sprite_coord, int scale = 1, bool transparent = true)
        {
            sprites_ = sprites;
            win_surf_ = win_surf;
            sprite_coord_ = sprite_coord;
            scale_ = scale;
            transparent_ = transparent;
        }

        void draw(int x, int y);

    public:
        SDL_Rect sprite_coord_;
        int scale_;
        bool transparent_;
        SDL_Surface* sprites_ = nullptr;
        SDL_Surface* win_surf_ = nullptr;
};

#endif