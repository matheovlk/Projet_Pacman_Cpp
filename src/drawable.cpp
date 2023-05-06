#include "window.hpp"
#include "drawable.hpp"

#include <SDL2/SDL.h>
#include <iostream>

Drawable::Drawable(SDL_Surface* sprites, SDL_Surface* win_surf, const SDL_Rect& sprite_coord, const unsigned char scale, const bool transparent, const char offset)
{
    sprites_ = sprites;
    win_surf_ = win_surf;
    sprite_coord_ = sprite_coord;
    scale_ = scale;
    transparent_ = transparent;
    offset_ = offset;
}

void Drawable::draw(const int x, const int y)
{
    if (transparent_)
    {
        SDL_SetColorKey(sprites_, true, 0);
    }
    else
    {
        SDL_SetColorKey(sprites_, false, 0);

    }

    SDL_Rect location = { x ,y+offset_, (sprite_coord_.w * scale_) , (sprite_coord_.h * scale_)};
    SDL_BlitScaled(sprites_, &sprite_coord_, win_surf_, &location);
}
