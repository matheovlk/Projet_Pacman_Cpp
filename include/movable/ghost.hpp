#pragma once

#include "movable.hpp"
#include <iostream>
#include <random>
#include <vector>

class Ghost: public Movable
{
    public:
        Ghost(SDL_Surface* sprites,SDL_Surface* win_surf)
        {
            sprites_ = sprites;
            transparent_ = true;
            win_surf_ = win_surf;
            animation_textures =
            {{Direction::RIGHT, 
                {{GHOST_RIGHT_1_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_RIGHT_2_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {Direction::LEFT, 
                {{GHOST_LEFT_1_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_LEFT_2_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {Direction::UP, 
                {{GHOST_UP_1_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_UP_2_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
            {Direction::DOWN, 
                {{GHOST_DOWN_1_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
                {GHOST_DOWN_2_SPRITE_X, BLINKY_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}}
            };
            direction_ = Direction::LEFT;
            current_texture = animation_textures.find(direction_)->second;
            sprite_coord_ = current_texture[0];
            nb_anim_frames = 2;
            scale_ = BASIC_SPRITE_SCALE;
            transparent_ = true;
        }

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