# pragma once

#include <vector>
#include <SDL2/SDL.h> 
#include "drawable.hpp"
#include "constants.hpp"

class Lives
{
    public:

        Lives(){};

        Lives(SDL_Surface* sprites,SDL_Surface* win_surf)
        {
            for (int i = 0; i < this->lives; i++)
            {
                this->lives_drawables.push_back(Drawable{sprites, win_surf, life_sprite, BASIC_SPRITE_SCALE, false, FOOTER_OFFSET});
            } 
        };

        void remove_life()
        {
            this->lives --;
            lives_drawables[lives].set_sprite(empty_sprite);
        };
        
        void restore_lives(){
            this->lives = 4;
            for (int i = 0; i < this->lives; i++)
            {
                this->lives_drawables[i].set_sprite(life_sprite);
            } 
        };

        void draw_lives()
        {
            for (int i = 0; i < lives_drawables.size(); i++) {
                lives_drawables[i].draw(i * CHARACTER_SPRITE_W * BASIC_SPRITE_SCALE + i * 10 + 50, 10 );
            }
        }

    private:
        unsigned char lives = 4;
        SDL_Rect life_sprite = {PACMAN_LEFT_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H};
        SDL_Rect empty_sprite = {160, 100, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H};

        std::vector<Drawable> lives_drawables;



};