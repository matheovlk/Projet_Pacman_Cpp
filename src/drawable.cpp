#include "window.h"

#include "drawable.h"

#include <SDL2/SDL.h>
#include <iostream>


void Drawable::draw(int x, int y)
{
    if (transparent_)
    {
        SDL_SetColorKey(sprites_, true, 0);
    }
    else
    {
        SDL_SetColorKey(sprites_, false, 0);

    }
    SDL_Rect location = { x ,y, (sprite_coord_.w * scale_) , (sprite_coord_.h * scale_)};
    SDL_BlitScaled(sprites_, &sprite_coord_, win_surf_, &location);
}
