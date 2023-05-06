#include "eatable.hpp"


Eatable::Eatable()
{
    scale_ = MAP_SPRITE_SCALE;
}

void Eatable::draw_itself()
{
    if(!eaten)
    {
        Drawable::draw(coord_on_map.x, coord_on_map.y);
    }
}
void Eatable::restart()
{
    eaten = false;
}

void Eatable::set_eaten()
{
    eaten = true;
}

unsigned int Eatable::board_position_to_xy(const unsigned char pos_on_board,const unsigned char sprite_size)
{
    const float spritee_offset = sprite_size / 2 * GUM_SPRITE_SCALE;
    return static_cast<unsigned int>(pos_on_board) * static_cast<unsigned int>(CELL_SIZE) + static_cast<unsigned int>(CELL_SIZE) / 2 - spritee_offset;
}