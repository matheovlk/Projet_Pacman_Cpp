#pragma once

#include "movable.hpp"
#include <iostream>
#include <random>
#include <vector>

class Ghost: public Movable
{
    public:
        Ghost(){};

        void move(Board_cells& board, int& nb_eaten_gum)
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
                const bool can_pass_left = left_cell->get_pac_can_pass();
                const bool can_pass_right = right_cell->get_pac_can_pass();
                const bool can_pass_up = up_cell->get_pac_can_pass();
                const bool can_pass_down = down_cell->get_pac_can_pass();
                
                if (can_pass_left && (direction_ != Direction::RIGHT || !can_pass_right))
                    next_possible_directs.push_back(Direction::LEFT);
                if (can_pass_right && (direction_ != Direction::LEFT || !can_pass_left ))
                    next_possible_directs.push_back(Direction::RIGHT);
                if (can_pass_up && (direction_ != Direction::DOWN || !can_pass_down))
                    next_possible_directs.push_back(Direction::UP);
                if (can_pass_down && (direction_ != Direction::UP || !can_pass_up))
                    next_possible_directs.push_back(Direction::DOWN);
                
                if (up_cell->get_cell_type() == Cell_type::Door && can_pass_door(nb_eaten_gum))
                    next_possible_directs = std::vector<Direction> {Direction::UP};

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

            virtual bool can_pass_door(int& nb_eaten_gum){return false;}

};