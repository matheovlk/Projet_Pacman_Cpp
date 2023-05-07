#include <iostream>

#include "movable.hpp"

void Movable::set_position(const unsigned int& x, const unsigned int& y)
{
    position.x = x;
    position.y = y;
}

void Movable::draw(const bool& update_anim)
{
    if (update_anim)
    {
        sprite_coord_ = current_texture[animation_index % nb_anim_frames];
        animation_index++;
    }

    Drawable::draw(position.x - (sprite_coord_.w * scale_  / 2), position.y - (sprite_coord_.h * scale_ / 2));
}

void Movable::move(Board_cells& board)
{
    const unsigned char half_cell_size = CELL_SIZE / 2;

    switch(direction_)
    {
        case Direction::LEFT:
        {
            // if in left tunnel
            if (position.x == 0)
                position.x = MAP_WIDTH * CELL_SIZE - 1;
            //if near left tunnel
            else if (position.x <= half_cell_size)
                position.x --;
            else if
            (
                board[floor((position.x - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))][floor(position.y / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.y % CELL_SIZE == half_cell_size
            )
                position.x --;
            break;
        }
        case Direction::RIGHT:
        {
            // if in left tunnel
            if (position.x == MAP_WIDTH * CELL_SIZE  - 1)
                position.x = 0;
            // near left tunnel
            else if (floor(position.x / CELL_SIZE + 1) == MAP_WIDTH && position.x + half_cell_size > MAP_WIDTH)
                position.x ++;
            else if
            (
                board[floor((position.x + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))][floor(position.y / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.y % CELL_SIZE == half_cell_size
            )
                position.x ++;
            break;
        }
        case Direction::UP:
        {
            if
            (
                board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.x % CELL_SIZE == half_cell_size
            )
                position.y --;
            break;
        }
        case Direction::DOWN:
        {
            if
            (
                board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.x % CELL_SIZE == half_cell_size
            )
                position.y ++;
            break;
        }
    }

}