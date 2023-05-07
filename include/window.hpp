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

        int start();

    private:
        int init(SDL_Window* &pWindow, SDL_Surface* &win_surf, SDL_Surface* &sprites);
        void run_game();
};