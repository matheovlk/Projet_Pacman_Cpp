#pragma once

#include "eatable.hpp"

class Fruit: public Eatable
{
    public:
        Fruit(const unsigned char& x_on_board, const unsigned char& y_on_board, SDL_Surface* sprites, SDL_Surface* win_surf);
        void appear(int nb_eaten_gum);
        void set_eaten_fruit();

    private:
        bool eaten_first_fruit = false;
        bool eaten_second_fruit = false;
};
