#pragma once

#include "movable.hpp"
#include <iostream>
#include <random>
#include <vector>
// #include "inky.hpp"
// #include "pinky.hpp"
// #include "blinky.hpp"
// #include "clyde.hpp"


// struct Ghosts {
//     Blinky blinky;
//     Inky inky;
//     Pinky pinky;
//     Clyde clyde;
// };

class Ghost: public Movable
{
    public:
        Ghost(){};

        void move(Board_cells& board) override
        {
            const unsigned char half_cell_size = CELL_SIZE / 2;
            Movable::move(board);

            // ghost in midle of a cell (could change direction)
            if (position.y % CELL_SIZE == half_cell_size && position.x % CELL_SIZE == half_cell_size)
            {
                std::vector<Direction> next_possible_directs = {};
                Cell * left_cell = board[static_cast<int>(floor((position.x - (half_cell_size + 1)) / CELL_SIZE)) % MAP_WIDTH][floor(position.y / static_cast<unsigned int>(CELL_SIZE))].get();
                Cell * right_cell = board[static_cast<int>(floor((position.x + half_cell_size) / (CELL_SIZE))) % MAP_WIDTH][floor(position.y / static_cast<unsigned int>(CELL_SIZE))].get();
                Cell * up_cell = board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))].get();
                Cell * down_cell = board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y + half_cell_size) / static_cast<unsigned int>(CELL_SIZE))].get();
                if (left_cell->get_pac_can_pass() && direction_ != Direction::RIGHT)
                    next_possible_directs.push_back(Direction::LEFT);
                if (right_cell->get_pac_can_pass() && direction_ != Direction::LEFT)
                    next_possible_directs.push_back(Direction::RIGHT);
                if (up_cell->get_pac_can_pass() && direction_ != Direction::DOWN)
                    next_possible_directs.push_back(Direction::UP);
                if (down_cell->get_pac_can_pass() && direction_ != Direction::UP)
                    next_possible_directs.push_back(Direction::DOWN);

                std::cout << static_cast<int>(next_possible_directs[0]);
                if (open_directions != next_possible_directs)
                {
                    open_directions = next_possible_directs;
                    std::random_device rd;  // a seed source for the random number engine
                    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
                    std::uniform_int_distribution<> distrib(0, open_directions.size() - 1);
                    direction_ = next_possible_directs[distrib(gen)]; // pour obtenir une direction aléatoire
                    current_texture = animation_textures.find(direction_)->second;
                }
            };
        }

        private:
            std::vector<Direction> open_directions = {};

};