#pragma once

#include <map>
#include <iostream>
#include <memory>
#include "movable.h"
#include "constants.h"
#include "cell.hpp"

using Board_cells = std::array<std::array<std::unique_ptr<Cell>, MAP_HEIGHT>, MAP_WIDTH>;


class Pacman: public Movable
{
    public:
        Pacman(SDL_Surface* sprites,SDL_Surface* win_surf)
        {
            sprites_ = sprites;
            transparent_ = true;
            win_surf_ = win_surf;
            sprite_coord_ = SDL_Rect {PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H};
            pacman_textures =
            {{RIGHT, 
                {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_RIGHT_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_RIGHT_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {LEFT, 
                {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_LEFT_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_LEFT_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {UP, 
                {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_UP_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_UP_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {DOWN, 
                {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_DOWN_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {PACMAN_DOWN_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}}
            
            };
            direction_ = RIGHT;
            animation_textures = pacman_textures.find(direction_)->second;
            sprite_coord_ = animation_textures[0];
            nb_anim_frames = 3;
            scale_ = BASIC_SPRITE_SCALE;
            transparent_ = true;
        }

        void move(Board_cells&);

        void set_direction(Direction, Board_cells&);



        Coordinates<unsigned char> get_position_on_map();

        private:

            std::map<Direction ,std::vector<SDL_Rect>> pacman_textures;


};