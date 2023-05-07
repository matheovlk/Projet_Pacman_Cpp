#include "clyde.hpp"

// Orange ghost, is inside and goes out after 60 eaten gum
Clyde::Clyde(SDL_Surface* sprites,SDL_Surface* win_surf)
{
    this->sprites_ = sprites;
    this->transparent_ = true;
    this->win_surf_ = win_surf;
    this->animation_textures =
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
    this->direction_ = Direction::LEFT;
    this->current_texture = animation_textures.find(direction_)->second;
    this->sprite_coord_ = current_texture[0];
    this->nb_anim_frames = 2;
    this->scale_ = BASIC_SPRITE_SCALE;
    this->transparent_ = true;
}

bool Clyde::can_pass_door(int& nb_eaten_gum)
{
    if (nb_eaten_gum >= 60)
        return true;
    return false;
}
