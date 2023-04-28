#include <iostream>

#include "constants.h"

#include "game.h"
#include "pacman.h"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>  Game::sketch_to_board(std::array<std::string, MAP_HEIGHT> &sketch, Pacman &pacman)
{
	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> board{};

	for (unsigned char y = 0; y < MAP_HEIGHT; y++)
	{
		for (unsigned char x = 0; x < MAP_WIDTH; x++)
		{
            board[x][y] = Cell::Empty;
			switch (sketch[y][x])
			{
				case 'w':
				{
					board[x][y] = Cell::Wall;
					break;
				}
				case 'P':
				{
					pacman.set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
					board[x][y] = Cell::Empty;
				}
                default:
                {
					board[x][y] = Cell::Empty;
                }
			}
		}
	}

	return board;
}