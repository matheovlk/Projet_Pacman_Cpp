#include "board.hpp"


Board_cells Board::sketch_to_board(const std::array<std::string, MAP_HEIGHT> sketch, Pacman& pacman, Ghost& ghost, SDL_Surface* sprites,SDL_Surface* win_surf)
{
	Board_cells board;


	// auto for loop iterator because we dont care of iterator type
	for (auto y = 0; y < MAP_HEIGHT; y++)
	{
		for (auto x = 0; x < MAP_WIDTH; x++)
		{
			switch (sketch[y][x])
			{

				case 'w':
				{
					board[x][y] = std::make_unique<NonEatable>(false);
					break;
				}
				case 'P':
				{
					// Initial Pacman position
					pacman.set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
					board[x][y] = std::make_unique<NonEatable>();
					break;
				}
				case 'R':
				{
					// Initial Pacman position
					ghost.set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
					board[x][y] = std::make_unique<NonEatable>();
					break;
				}
				case ' ':
				{
					board[x][y] = std::make_unique<NonEatable>();
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
					board[x][y] = std::make_unique<NonEatable>();
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

	Coordinates<unsigned char> pacman_coord = pacman.get_position_on_board();
	
	Cell* pacman_cell = board[pacman_coord.x][pacman_coord.y].get();

	Cell_type cell_type = pacman_cell->get_cell_type();

	if (cell_type == Cell_type::Gum || cell_type == Cell_type::Super_gum)
		{
			auto eatable_ptr = dynamic_cast<Eatable*>(pacman_cell);
			eatable_ptr->set_eaten();
		}

}
