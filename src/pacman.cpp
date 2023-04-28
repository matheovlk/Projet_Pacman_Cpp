# include "pacman.h"

void Pacman::draw()
{
    Drawable::draw(x_ - (sprite_coord_.w * scale_ / 2), y_ - (sprite_coord_.h * scale_ / 2));
}

void Pacman::go_up()
{
    y_ -= MAP_SPRITE_SCALE;
}

void Pacman::go_down()
{
    y_ += MAP_SPRITE_SCALE;
}

void Pacman::go_right()
{
    x_ += MAP_SPRITE_SCALE;
}

void Pacman::go_left()
{
    x_ -= MAP_SPRITE_SCALE;
}