# include "pacman.h"

void Pacman::draw()
{
    Drawable::draw(x_ - (sprite_coord_.w * scale_ / 2), y_ - (sprite_coord_.h * scale_ / 2));
}

void Pacman::set_direction(Direction direction, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& board)
{
    unsigned char x_on_board = static_cast<unsigned int>(floor(x_ / static_cast<unsigned int>(CELL_SIZE) / static_cast<unsigned int>(MAP_SPRITE_SCALE)));
    unsigned char y_on_board = static_cast<unsigned int>(floor(y_ / static_cast<unsigned int>(CELL_SIZE) / static_cast<unsigned int>(MAP_SPRITE_SCALE)));

    std::cout << +x_on_board << std::endl;
    std::cout << +y_on_board << std::endl;
    switch(direction)
    {
        case LEFT:
        {
            if (board[x_on_board - 1][y_on_board] == Empty)
                direction_ = LEFT;
            break;
        }
        case RIGHT:
        {
            if (board[x_on_board - 1][y_on_board] == Empty)
                direction_ = RIGHT;
            break;
        }
        case UP:
        {
            if (board[x_on_board][y_on_board - 1] == Empty)
                direction_ = UP;
            break;
        }
        case DOWN:
        {
            if (board[x_on_board - 1][y_on_board + 1] == Empty)
                direction_ = DOWN;
            break;

        }
    }
}

void Pacman::move(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& board)
{

    unsigned char x_on_board = static_cast<unsigned int>(floor(x_ / static_cast<unsigned int>(CELL_SIZE) / static_cast<unsigned int>(MAP_SPRITE_SCALE)));
    unsigned char y_on_board = static_cast<unsigned int>(floor(y_ / static_cast<unsigned int>(CELL_SIZE) / static_cast<unsigned int>(MAP_SPRITE_SCALE)));

    std::cout << +x_on_board << std::endl;
    std::cout << +y_on_board << std::endl;
    
    switch(direction_)
    {
        case LEFT:
        {
            if (board[x_on_board - 1][y_on_board] == Empty)
                x_ -= MAP_SPRITE_SCALE;
            break;
        }
        case RIGHT:
        {
            if (board[x_on_board - 1][y_on_board] == Empty)
                x_ += MAP_SPRITE_SCALE;
            break;
        }
        case UP:
        {
            if (board[x_on_board][y_on_board - 1] == Empty)
                y_ -= MAP_SPRITE_SCALE;
            break;
        }
        case DOWN:
        {
            if (board[x_on_board - 1][y_on_board + 1] == Empty)
                y_ += MAP_SPRITE_SCALE;
            break;

        }
    }
}