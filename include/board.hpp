#pragma once
#include "pacman.hpp"
#include "ghost.hpp"
#include "constants.hpp"
#include "pacgum.hpp"
#include "superPacgum.hpp"
#include "nonEatable.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <array>
class Board
{
    public:
        
        Board(const std::array<std::string, MAP_HEIGHT> map_sketch, Pacman& pacman, Ghost& ghost, SDL_Surface* sprites,SDL_Surface* win_surf){
            board = sketch_to_board(map_sketch, pacman, ghost, sprites, win_surf);
        }

        Board_cells& get_board_cells(){
            return board;
        }

        void interract(Pacman& pacman);

        void draw();
    private:
        Board_cells board;
        Board_cells sketch_to_board(const std::array<std::string, MAP_HEIGHT>, Pacman&, Ghost& ghost, SDL_Surface* sprites,SDL_Surface* win_surf);

};