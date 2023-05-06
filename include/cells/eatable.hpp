#pragma once

#include "drawable.h"
#include "cell.hpp"

class Eatable: public Cell, public Drawable
{
    public:
        Eatable(){
            scale_ = MAP_SPRITE_SCALE;
        };

        void draw_itself() {
            if (eaten)
            {

            }
            else
            {
                Drawable::draw(coord_on_map.x, coord_on_map.y);
            }
        }

        void display(){};
        
        void restart();

        void set_eaten();

    private:

        bool eaten = false;
    protected:
        Coordinates<unsigned int> coord_on_map;
        Coordinates<unsigned char> coord_on_board;

        unsigned int board_position_to_xy(unsigned char pos_on_board, unsigned char sprite_size)
        {
            const float spritee_offset = sprite_size / 2 * GUM_SPRITE_SCALE;
            return static_cast<unsigned int>(pos_on_board) * static_cast<unsigned int>(CELL_SIZE) + static_cast<unsigned int>(CELL_SIZE) / 2 - spritee_offset;
        }
};