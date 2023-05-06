#pragma once

#include "drawable.hpp"
#include <vector>
#include <map>

class Character: public Drawable
{
    public:
        Character(){};
        Character(SDL_Surface* sprites,SDL_Surface* win_surf);
        std::map<int, SDL_Rect> get_number_textures();
        SDL_Rect get_specific_texture(int specific_texture);
    
    private:
        std::map<int, SDL_Rect> number_textures;
        // SDL_Rect zero_texture;
        // SDL_Rect one_texture;
        // SDL_Rect two_texture;
        // SDL_Rect three_texture;
        // SDL_Rect four_texture;
        // SDL_Rect five_texture;
        // SDL_Rect six_texture;
        // SDL_Rect seven_texture;
        // SDL_Rect eight_texture;
        // SDL_Rect nine_texture;
};
