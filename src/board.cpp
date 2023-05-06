#include "board.hpp"
#include "pacgum.hpp"
#include "superPacgum.hpp"
#include "constants.h"
#include "empty.hpp"
#include <iostream>

Board_cells Board::sketch_to_board(std::array<std::string, MAP_HEIGHT> sketch, Pacman& pacman, SDL_Surface* sprites,SDL_Surface* win_surf)
{
	Board_cells board;

	for (unsigned char y = 0; y < MAP_HEIGHT; y++)
	{
		for (unsigned char x = 0; x < MAP_WIDTH; x++)
		{
			switch (sketch[y][x])
			{

				case 'w':
				{
					board[x][y] = std::make_unique<Empty>(false);
					break;
				}
				case 'P':
				{
					pacman.set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
					board[x][y] = std::make_unique<Empty>();
					break;
				}
				case ' ':
				{
					board[x][y] = std::make_unique<Empty>();
					break;
				}
				case '.':
				{
					board[x][y] = std::make_unique<Pacgum>(x, y, sprites, win_surf);
					break;
				}
				case 'o':
				{
					board[x][y] = std::make_unique<SuperPacgum>(x, y, sprites, win_surf);
					break;
				}
                default:
                {
					board[x][y] = std::make_unique<Empty>();
				}					

			}
		}
	}

	return board;
}

void Board::draw()
{
	for (auto& row : board)
	{
        for (auto& cell : row)
		{
			Cell_type cell_type = cell->get_cell_type();
			if (cell_type == Cell_type::Gum || cell_type == Cell_type::Super_gum)
			{
				auto eatable_ptr = dynamic_cast<Eatable*>(cell.get());
				eatable_ptr->draw_itself();
			}
        }
    }
}

void Board::interract(Pacman& pacman){
	Coordinates<unsigned char> pacman_coord = pacman.get_position_on_map();
	Cell* pacman_cell = board[pacman_coord.x][pacman_coord.y].get();
	Cell_type cell_type = pacman_cell->get_cell_type();
	if (cell_type == Cell_type::Gum || cell_type == Cell_type::Super_gum)
		{
			auto eatable_ptr = dynamic_cast<Eatable*>(pacman_cell);
			eatable_ptr->set_eaten();
		}

}
