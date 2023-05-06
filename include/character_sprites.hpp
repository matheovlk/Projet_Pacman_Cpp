#pragma once

#include "drawable.hpp"
#include "constants.hpp"
#include "score.hpp"
#include <vector>
#include <map>

class Character_sprites: public Drawable
{
    public:
        Character_sprites(){};
        Character_sprites(SDL_Surface* sprites, SDL_Surface* win_surf);
        std::map<int, SDL_Rect> get_number_textures();
        void set_specific_texture(int specific_texture);
    
    private:
        std::map<int, SDL_Rect> number_textures;
};
