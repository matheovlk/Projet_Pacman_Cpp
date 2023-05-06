#pragma once

#include "eatable.hpp"

class SuperPacgum: public Eatable
{
    public:
        SuperPacgum(const unsigned char& x_on_board, const unsigned char& y_on_board, SDL_Surface* sprites,SDL_Surface* win_surf);
};