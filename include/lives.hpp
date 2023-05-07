# pragma once

#include <vector>
#include <SDL2/SDL.h> 
#include "drawable.hpp"
#include "constants.hpp"

class Lives
{
    public:

        Lives(){};

        Lives(SDL_Surface* sprites,SDL_Surface* win_surf);

        void remove_life();        
        void restore_lives();
        bool game_over();
        void draw_lives();

    private:
        unsigned char max_lives = 4;
        unsigned char lives = max_lives;
        SDL_Rect life_sprite = {PACMAN_LEFT_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H};
        SDL_Rect empty_sprite = {160, 100, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H};

        std::vector<Drawable> lives_drawables;



};
