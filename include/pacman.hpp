#pragma once

#include <map>
#include <iostream>
#include <memory>
#include "movable.hpp"
#include "constants.hpp"
#include "cell.hpp"

using Board_cells = std::array<std::array<std::unique_ptr<Cell>, MAP_HEIGHT>, MAP_WIDTH>;

class Pacman: public Movable
{
    public:
        Pacman(SDL_Surface* sprites, SDL_Surface* win_surf);

        void move(Board_cells&);

        void set_direction(Direction, const Board_cells&);

        Coordinates<unsigned char> get_position_on_map();

        private:
            std::map<Direction ,std::vector<SDL_Rect>> pacman_textures;

};