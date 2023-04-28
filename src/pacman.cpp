# include "pacman.h"

void Pacman::draw()
{
    Drawable::draw(x_ - (sprite_coord_.w * scale_  / 2), y_ - (sprite_coord_.h * scale_ / 2));
}

void Pacman::set_direction(Direction direction, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& board)
{

    const unsigned char half_cell_size = CELL_SIZE / 2;


    switch(direction)
    {
        case LEFT:
        {
            if
            (
                board[floor((x_ - half_cell_size) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                y_ % CELL_SIZE == half_cell_size
            )
                direction_ = LEFT;
            break;
        }
        case RIGHT:
        {
            if
            (
                board[floor((x_ + half_cell_size) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                y_ % CELL_SIZE == half_cell_size
            )
                direction_ = RIGHT;
            break;
        }
        case UP:
        {
            if
            (
                board[floor((x_ - half_cell_size) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                x_ % CELL_SIZE == half_cell_size
            )
                direction_ = UP;
            break;
        }
        case DOWN:
        {
            if
            (
                board[floor((x_ + half_cell_size) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                x_ % CELL_SIZE == half_cell_size
            )
                direction_ = DOWN;
            break;
        }
    }
}

void Pacman::move(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& board)
{

    unsigned char x_on_board = static_cast<unsigned int>(floor(x_ / static_cast<unsigned int>(CELL_SIZE) / static_cast<unsigned int>(MAP_SPRITE_SCALE)));
    unsigned char y_on_board = static_cast<unsigned int>(floor(y_ / static_cast<unsigned int>(CELL_SIZE) / static_cast<unsigned int>(MAP_SPRITE_SCALE)));
    const unsigned char half_cell_size = CELL_SIZE / 2;

    // std::cout << y_ % CELL_SIZE << std::endl;
    // std::cout << +half_cell_size << std::endl;
    // std::cout << board[floor((x_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] << std::endl;


    switch(direction_)
    {
        case LEFT:
        {
            if
            (
                board[floor((x_ - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))][floor(y_ / static_cast<unsigned int>(CELL_SIZE))] == Empty && \
                y_ % CELL_SIZE == half_cell_size
            )
                x_--;
            break;
        }
        case RIGHT:
        {
            if
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