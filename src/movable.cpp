#include <iostream>

#include "movable.hpp"

void Movable::set_position(const unsigned int& x, const unsigned int& y)
{
    position.x = x;
    position.y = y;
}

void Movable::draw(const bool& update_anim)
{
    if (update_anim)
    {
        sprite_coord_ = animation_textures[animation_index % nb_anim_frames];
        animation_index++;
    }

    Drawable::draw(position.x - (sprite_coord_.w * scale_  / 2), position.y - (sprite_coord_.h * scale_ / 2));
}