
#include "game.hpp"



bool Game::get_update_animation_index()
{
	game_animation_index++;
	if (!(game_animation_index = game_animation_index % 10))
		return true;
	return false;
}