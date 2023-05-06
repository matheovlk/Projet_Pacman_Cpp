#include "character_sprites.hpp"
#include <vector>

Character_sprites::Character_sprites(SDL_Surface* sprites, SDL_Surface* win_surf)
{
    scale_ = CHAR_SPRITE_SCALE;
    transparent_ = true;

    number_textures =
    {{0, 
        {4, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {1, 
        {12, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {2, 
        {20, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {3, 
        {28, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {4, 
        {36, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {5, 
        {44, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {6, 
        {52, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {7, 
        {60, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {8, 
        {68, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}},
    {9, 
        {76, CHARACTER_SPRITE_Y, NUMBER_SPRITE_W, NUMBER_SPRITE_H}}
    };

    this->sprites_ = sprites;
    this->win_surf_ = win_surf;
}

std::map<int, SDL_Rect> Character_sprites::get_number_textures()
{
    return number_textures;
}

void Character_sprites::set_specific_texture(int specific_texture)
{
    this->sprite_coord_ = number_textures.find(specific_texture)->second;
}
