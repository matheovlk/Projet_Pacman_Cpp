#pragma once

#include <vector>
#include <SDL2/SDL.h> 
#include <string>
#include <iostream>

#include "constants.hpp"
#include "drawable.hpp"



class Word: public Drawable
{
    public :
        Word(){};
        
        Word(SDL_Surface* sprites, SDL_Surface* win_surf): Drawable(sprites, win_surf, WORD_OFFSET) {this->transparent_ = false;};
        
        // for strings
        void set_word(std::string word);

        void draw(int x, int y);
    
        // for ints
        void set_word(int number);

    private :
        std::vector<SDL_Rect> word_sprites;

        SDL_Rect space_sprite = {CHARACTER_0SPACEP_X, CHARACTER_A_O_Y, CHARACTER_SIZE, CHARACTER_SIZE};
        SDL_Rect exclamation_sprite = {CHARACTER_EXCLAL_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE};
        std::vector<SDL_Rect> letter_sprites {
            {CHARACTER_1AQ_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_2BR_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_3CS_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_4DT_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_5EU_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_6FV_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_7GW_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_8HX_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_9IY_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_JZ_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_K_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_EXCLAL_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_M_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_N_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_O_X, CHARACTER_A_O_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_0SPACEP_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_1AQ_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_2BR_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_3CS_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_4DT_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_5EU_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_6FV_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_7GW_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_8HX_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_9IY_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_JZ_X, CHARACTER_P_Z_Y, CHARACTER_SIZE ,CHARACTER_SIZE}
        };

        std::vector<SDL_Rect> number_sprites {
            {CHARACTER_0SPACEP_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_1AQ_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_2BR_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_3CS_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_4DT_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_5EU_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_6FV_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_7GW_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_8HX_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE},
            {CHARACTER_9IY_X, CHARACTER_0_9_Y, CHARACTER_SIZE ,CHARACTER_SIZE}
        };

};