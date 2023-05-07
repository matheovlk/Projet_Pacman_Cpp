#pragma once

#include "ghost.hpp"

class Inky: public Ghost
{
    public:
        Inky(SDL_Surface* sprites,SDL_Surface* win_surf);

        bool can_pass_door(int& nb_eaten_gum) override;
};
