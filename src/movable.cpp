#include "movable.h"

void Movable::set_position(unsigned int x, unsigned int y)
{
    x_ = x * MAP_SPRITE_SCALE;
    y_ = y * MAP_SPRITE_SCALE;
}