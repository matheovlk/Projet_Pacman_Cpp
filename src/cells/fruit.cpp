#include "fruit.hpp"

Fruit::Fruit(const unsigned char& x_on_board, const unsigned char& y_on_board, SDL_Surface* sprites,SDL_Surface* win_surf)
{
    cell_type = Cell_type::Fruit;
    sprites_ = sprites;
    win_surf_ = win_surf;
    sprite_coord_ = SDL_Rect {CHERRY_SPRITE_X, CHERRY_SPRITE_Y, FRUIT_SPRITE_SIZE, FRUIT_SPRITE_SIZE};
    coord_on_board = {x_on_board, y_on_board};
    coord_on_map = {board_position_to_xy(x_on_board, FRUIT_SPRITE_SIZE), board_position_to_xy(y_on_board, FRUIT_SPRITE_SIZE)};
}