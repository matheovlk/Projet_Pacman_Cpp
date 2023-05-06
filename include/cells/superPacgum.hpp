#pragma once

#include "eatable.hpp"

class SuperPacgum: public Eatable
{
    public:

        SuperPacgum(unsigned char x_on_board, unsigned char y_on_board, SDL_Surface* sprites,SDL_Surface* win_surf)
        {
            cell_type = Cell_type::Super_gum;
            sprites_ = sprites;
            win_surf_ = win_surf;
            sprite_coord_ = SDL_Rect {SUPERGUM_SPRITE_X, SUPERGUM_SPRITE_Y, SUPERGUM_SPRITE_SIZE, SUPERGUM_SPRITE_SIZE};
            coord_on_board = {x_on_board, y_on_board};
            coord_on_map = {board_position_to_xy(x_on_board, SUPERGUM_SPRITE_SIZE), board_position_to_xy(y_on_board, SUPERGUM_SPRITE_SIZE)};
        };



};