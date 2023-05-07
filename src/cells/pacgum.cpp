#include "pacgum.hpp"

Pacgum::Pacgum(const unsigned char &x_on_board, const unsigned char &y_on_board, SDL_Surface* sprites,SDL_Surface* win_surf)
{
    cell_type = Cell_type::Gum;
    sprites_ = sprites;
    win_surf_ = win_surf;
    sprite_coord_ = SDL_Rect {PACGUM_SPRITE_X, PACGUM_SPRITE_Y, PACGUM_SPRITE_SIZE, PACGUM_SPRITE_SIZE};
    coord_on_board = {x_on_board, y_on_board};
    coord_on_map = {board_position_to_xy(x_on_board, PACGUM_SPRITE_SIZE, GUM_SPRITE_SCALE),
                                        board_position_to_xy(y_on_board, PACGUM_SPRITE_SIZE, GUM_SPRITE_SCALE)};
};
