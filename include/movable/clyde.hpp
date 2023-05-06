#pragma once

#include "ghost.hpp"

class Clyde: public Ghost
{
    public:
    
        Clyde(SDL_Surface* sprites,SDL_Surface* win_surf)
        {
            sprites_ = sprites;
            transparent_ = true;
            win_surf_ = win_surf;
            animation_textures =
            {{Direction::RIGHT, 
                {{GHOST_RIGHT_1_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_RIGHT_2_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {Direction::LEFT, 
                {{GHOST_LEFT_1_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_LEFT_2_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {Direction::UP, 
                {{GHOST_UP_1_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_UP_2_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {Direction::DOWN, 
                {{GHOST_DOWN_1_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_DOWN_2_SPRITE_X, CLYDE_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}}
            };
            direction_ = Direction::LEFT;
            current_texture = animation_textures.find(direction_)->second;
            sprite_coord_ = current_texture[0];
            nb_anim_frames = 2;
            scale_ = BASIC_SPRITE_SCALE;
            transparent_ = true;
        }
};