#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "game.hpp"

class Window
{

    public:
    
        Window(){};

        SDL_Window* pWindow = nullptr;
        SDL_Surface* win_surf = nullptr;
        SDL_Surface* sprites = nullptr;

        int start()
        {

            if (init(pWindow, win_surf, sprites) == 1)
            {
                std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
                return 1;
            }
            run_game();
            return 0;
        }

    private:
        int init(SDL_Window* &pWindow, SDL_Surface* &win_surf, SDL_Surface* &sprites);
        void run_game();
};