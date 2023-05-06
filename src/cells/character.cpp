#include "character.hpp"
#include "constants.hpp"
#include <vector>

Character::Character(SDL_Surface* sprites, SDL_Surface* win_surf)
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

    // zero_texture = number_textures.find(0)->second;
    // one_texture = number_textures.find(1)->second;
    // two_texture = number_textures.find(2)->second;
    // three_texture = number_textures.find(3)->second;
    // four_texture = number_textures.find(4)->second;
    // five_texture = number_textures.find(5)->second;
    // six_texture = number_textures.find(6)->second;
    // seven_texture = number_textures.find(7)->second;
    // eight_texture = number_textures.find(8)->second;
    // nine_texture = number_textures.find(9)->second;
}

std::map<int, SDL_Rect> Character::get_number_textures()
{
    return number_textures;
}

SDL_Rect Character::get_specific_texture(int specific_texture)
{
    return number_textures.find(specific_texture)->second;
}
