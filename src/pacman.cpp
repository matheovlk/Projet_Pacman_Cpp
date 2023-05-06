# include "pacman.h"
# include <iostream>

void Pacman::set_direction(Direction direction, Board_cells& board)
{

    const unsigned char half_cell_size = CELL_SIZE / 2;

    switch(direction)
    {
        case LEFT:
        {
            if
            (
                board[static_cast<int>(floor((x_ - (half_cell_size + 1)) / CELL_SIZE)) % MAP_WIDTH][floor(y_ / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                y_ % CELL_SIZE == half_cell_size
            )
            {
                direction_ = LEFT;
                animation_textures = pacman_textures.find(LEFT)->second;

            }
            break;
        }
        case RIGHT:
        {
            if
            (
                board[static_cast<int>(floor((x_ + half_cell_size) / (CELL_SIZE))) % MAP_WIDTH][floor(y_ / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                y_ % CELL_SIZE == half_cell_size
            )
            {
                direction_ = RIGHT;
                animation_textures = pacman_textures.find(RIGHT)->second;
            }
            break;
        }
        case UP:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                x_ % CELL_SIZE == half_cell_size
            )
            {
                direction_ = UP;
                animation_textures = pacman_textures.find(UP)->second;
            }
            break;
        }
        case DOWN:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ + half_cell_size) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                x_ % CELL_SIZE == half_cell_size
            )
            {
                direction_ = DOWN;
                animation_textures = pacman_textures.find(DOWN)->second;
            }
            break;
        }
    }
}

void Pacman::move(Board_cells& board)
{
    const unsigned char half_cell_size = CELL_SIZE / 2;

    switch(direction_)
    {
        case LEFT:
        {
            // if in left tunnel
            if (x_ == 0)
                x_ = MAP_WIDTH * CELL_SIZE;
            //if near left tunnel
            else if (x_ <= half_cell_size)
                x_--;
            else if
            (
                board[floor((x_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                y_ % CELL_SIZE == half_cell_size
            )
                x_--;
            break;
        }
        case RIGHT:
        {
            // if in left tunnel
            if (x_ == MAP_WIDTH * CELL_SIZE)
                x_ = 0;
            // near left tunnel
            else if (floor(x_ / CELL_SIZE + 1) == MAP_WIDTH && x_ + half_cell_size > MAP_WIDTH)
                x_++;
            else if
            (
                board[floor((x_ + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                y_ % CELL_SIZE == half_cell_size
            )
                x_++;
            break;
        }
        case UP:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                x_ % CELL_SIZE == half_cell_size
            )
                y_--;
            break;
        }
        case DOWN:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                x_ % CELL_SIZE == half_cell_size
            )
                y_++;
            break;
        }
    }

}

Coordinates<unsigned char> Pacman::get_position_on_map()
{

    unsigned char x_on_board = x_ / CELL_SIZE;
    unsigned char y_on_board = y_ / CELL_SIZE;
    return {x_on_board, y_on_board};

}
 