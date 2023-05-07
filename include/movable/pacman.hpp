#pragma once

#include <iostream>
#include "movable.hpp"
#include "constants.hpp"
#include "cell.hpp"

class Pacman: public Movable
{
    public:
        Pacman(SDL_Surface* sprites,SDL_Surface* win_surf);

        void set_direction(Direction ,const Board_cells&);

};