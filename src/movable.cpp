#include <iostream>

#include "movable.h"

void Movable::set_position(int x, int y)
{
    x_ = x;
    y_ = y;
}

void Movable::draw(unsigned char update_anim)
{
    if (update_anim)
    {
        sprite_coord_ = animation_textures[animation_index % nb_anim_frames];
        animation_index++;
    }

    Drawable::draw(x_ - (sprite_coord_.w * scale_  / 2), y_ - (sprite_coord_.h * scale_ / 2));
}