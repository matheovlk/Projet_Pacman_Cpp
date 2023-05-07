#include "board.hpp"

Board::Board(const std::array<std::string, MAP_HEIGHT> map_sketch, Pacman& pacman, std::vector<std::unique_ptr<Ghost>>& ghosts, SDL_Surface* sprites,SDL_Surface* win_surf){
	sketch_to_board(map_sketch, pacman, ghosts, sprites, win_surf);
}

void Board::sketch_to_board(const std::array<std::string, MAP_HEIGHT> sketch, Pacman& pacman, std::vector<std::unique_ptr<Ghost>>& ghosts, SDL_Surface* sprites,SDL_Surface* win_surf)
{

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
				case '1':
				{
					// Initial Blinky position
					ghosts[0]->set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
					board[x][y] = std::make_unique<NonEatable>();
					break;
				}				
				case '2':
				{
					// Initial Inky position
					ghosts[1]->set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
					board[x][y] = std::make_unique<NonEatable>();
					break;
				}				
				case '3':
				{
					// Initial Pinky position
					ghosts[2]->set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
					board[x][y] = std::make_unique<NonEatable>();
					break;
				}				
				case '4':
				{
					// Initial Clyde position
					ghosts[3]->set_position(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
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
				case 'D':
				{
					board[x][y] = std::make_unique<Door>();
					break;
				}
				// case 'F':
				// {
				// 	board[x][y] = std::make_unique<Fruit>(x, y, sprites, win_surf);
				// 	break;
				// }
                default:
                {
					board[x][y] = std::make_unique<NonEatable>();
				}
			}
		}
	}
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

const std::unique_ptr<Cell>& get_door(const std::array<std::array<std::unique_ptr<Cell>, MAP_HEIGHT>, MAP_WIDTH>& board, int value)
{
	// On parcourt le tableau à deux dimensions
	for (const auto& row : board) {
		for (const auto& cell : row) {
		// On vérifie si la cellule existe et si sa méthode get_type() renvoie la valeur voulue
		if (cell && cell->get_cell_type() == Cell_type::Door) {
			// On renvoie la cellule trouvée
			return cell;
		}
		}
	}
	// Si on n'a pas trouvé de cellule correspondante, on renvoie une référence à un pointeur nul
	static std::unique_ptr<Cell> null_ptr;
	return null_ptr;
}

void Board::interract(Pacman& pacman, Score& score){

	Coordinates<unsigned char> pacman_coord = pacman.get_position_on_board();
	
	Cell* pacman_cell = board[pacman_coord.x][pacman_coord.y].get();

	Cell_type cell_type = pacman_cell->get_cell_type();

	if (cell_type == Cell_type::Gum || cell_type == Cell_type::Super_gum)
	{
		auto eatable_ptr = dynamic_cast<Eatable*>(pacman_cell);
    if (eatable_ptr->get_eaten() == false) {
				score.update_score(cell_type);
		}
		if (cell_type == Cell_type::Gum && eatable_ptr->get_eaten() == false)
		{
			eaten_gum_nb++;
		}
		eatable_ptr->set_eaten();
	}
}

int& Board::get_eaten_gum_nb()
{
	return eaten_gum_nb;
}