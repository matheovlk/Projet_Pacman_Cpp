#pragma once

#include <array>
#include <iostream>
#include "movable.h"
#include "constants.h"

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
};

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
            direction_ = LEFT;
        }



        void move(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>&);

        void draw();

        void set_direction(Direction, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>&);

        private:

            Direction direction_;



};