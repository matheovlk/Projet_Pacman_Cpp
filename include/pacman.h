#pragma once

#include <array>
#include <iostream>
#include "movable.h"
#include "constants.h"



class Pacman: public Movable
{
    public:
        Pacman(SDL_Surface* sprites,SDL_Surface* win_surf)
        {
            sprites_ = sprites;
            win_surf_ = win_surf;
            sprite_coord_ = SDL_Rect {PACMAN_3_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H};
            animation_textures = 
            {
                {PACMAN_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_3_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}
            };
            nb_anim_frames = 3;
            scale_ = BASIC_SPRITE_SCALE;
            transparent_ = true;
            direction_ = RIGHT;
        }

        void move(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>&);

        void set_direction(Direction, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>&);

};