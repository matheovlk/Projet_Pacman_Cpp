#pragma once

#include <map>
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

        void move(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>&);

        void set_direction(Direction, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>&);

        private:

            std::map<Direction ,std::vector<SDL_Rect>> pacman_textures;


};