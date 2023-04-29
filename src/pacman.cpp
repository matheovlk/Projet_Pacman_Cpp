# include "pacman.h"

void Pacman::set_direction(Direction direction, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& board)
{

    const unsigned char half_cell_size = CELL_SIZE / 2;


    switch(direction)
    {
        case LEFT:
        {
            if
            (
                board[static_cast<int>(floor((x_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))) % 21][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                y_ % CELL_SIZE == half_cell_size
            )
                direction_ = LEFT;
            break;
        }
        case RIGHT:
        {
            if
            (
                board[static_cast<int>(floor((x_ + half_cell_size) / (CELL_SIZE))) % 21][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                y_ % CELL_SIZE == half_cell_size
            )
                direction_ = RIGHT;
            break;
        }
        case UP:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                x_ % CELL_SIZE == half_cell_size
            )
                direction_ = UP;
            break;
        }
        case DOWN:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ + half_cell_size) / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                x_ % CELL_SIZE == half_cell_size
            )
                direction_ = DOWN;
            break;
        }
    }
}

void Pacman::move(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& board)
{
    const unsigned char half_cell_size = CELL_SIZE / 2;


    switch(direction_)
    {
        case LEFT:
        {
            if (x_ == 0)
                x_ = MAP_WIDTH * CELL_SIZE;
            else if (x_ <= half_cell_size)
                x_--;
            else if
            (
                board[floor((x_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                y_ % CELL_SIZE == half_cell_size
            )
                x_--;
            break;
        }
        case RIGHT:
        {
            if (x_ == MAP_WIDTH * CELL_SIZE)
                x_ = 0;
            else if (floor(x_ / CELL_SIZE + 1) == MAP_WIDTH && x_ + half_cell_size > MAP_WIDTH)
                x_++;
            else if
            (
                board[floor((x_ + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                y_ % CELL_SIZE == half_cell_size
            )
                x_++;
            break;
        }
        case UP:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                x_ % CELL_SIZE == half_cell_size
            )
                y_--;
            break;
        }
        case DOWN:
        {
            if
            (
                board[floor(x_ / static_cast<unsigned int>(CELL_SIZE))][floor((y_ + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                x_ % CELL_SIZE == half_cell_size
            )
                y_++;
            break;
        }
    }
}