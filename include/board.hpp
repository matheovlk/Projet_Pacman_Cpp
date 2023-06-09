#pragma once
#include "pacman.hpp"
#include "ghost.hpp"
#include "constants.hpp"
#include "pacgum.hpp"
#include "superPacgum.hpp"
#include "nonEatable.hpp"
#include "score.hpp"
#include "door.hpp"
#include "fruit.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <array>
class Board
{
    public:
        
        Board(){};

        Board_cells& get_board_cells(){
            return board;
        }

        void interract(Pacman& pacman, Score& score);

        void draw();

        void reset_board(const std::array<std::string, MAP_HEIGHT>, Pacman&, std::vector<std::unique_ptr<Ghost>>& ghosts, SDL_Surface* sprites,SDL_Surface* win_surf);
        
        void sketch_to_board(const std::array<std::string, MAP_HEIGHT>, Pacman&, std::vector<std::unique_ptr<Ghost>>& ghosts, SDL_Surface* sprites,SDL_Surface* win_surf);

        bool check_collide_ghost(Pacman& pacman, std::vector<std::unique_ptr<Ghost>>& ghosts);

        int& get_eaten_gum_nb();

    private :

        Board_cells board;

        int eaten_gum_nb = 0;
};
