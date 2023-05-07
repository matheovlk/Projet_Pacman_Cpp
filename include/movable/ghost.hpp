#pragma once

#include "movable.hpp"
#include <iostream>
#include <random>
#include <vector>

class Ghost: public Movable
{
    public:
        Ghost(){};

        void move(Board_cells* board, int& nb_eaten_gum);

        private:
            std::vector<Direction> open_directions = {};
            
            virtual bool can_pass_door(int& nb_eaten_gum){return false;}

};
