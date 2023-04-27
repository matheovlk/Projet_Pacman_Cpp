#include "game.h"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>  Game::sketch_to_board(std::array<std::string, MAP_HEIGHT> &sketch)
{
	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> board{};

	for (unsigned char y = 0; y < MAP_HEIGHT; y++)
	{
		for (unsigned char x = 0; x < MAP_WIDTH; x++)
		{
            board[x][y] = Cell::Empty;

			switch (sketch[x][y])
			{
				//#wall #obstacle #youcantgothroughme
				case 'w':
				{
					board[x][y] = Cell::Wall;
					break;
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