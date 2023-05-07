#pragma once

#include "ghost.hpp"

class Blinky: public Ghost
{
    public:
        Blinky(SDL_Surface* sprites,SDL_Surface* win_surf);
};
