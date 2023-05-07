#pragma once

#include "drawable.hpp"
#include "cell.hpp"

class Eatable: public Cell, public Drawable
{
    public:
        Eatable();

        void draw_itself();

        void restart();

        void set_eaten(bool eaten);

        bool get_eaten();

    protected:
        bool eaten = false;
        Coordinates<unsigned int> coord_on_map;
        Coordinates<unsigned char> coord_on_board;

        unsigned int board_position_to_xy(unsigned char pos_on_board, unsigned char sprite_size, char scale);
};