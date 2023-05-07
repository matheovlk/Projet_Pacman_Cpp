#pragma once

#include "eatable.hpp"

class Pacgum: public Eatable
{
    public:
        Pacgum(const unsigned char &x_on_board, const unsigned char &y_on_board, SDL_Surface* sprites,SDL_Surface* win_surf);    
};