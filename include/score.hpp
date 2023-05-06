#pragma once

#include "drawable.hpp"
#include "character_sprites.hpp"

class Score
{
    public:

        Score(){};

        Score(SDL_Surface* sprites, SDL_Surface* win_surf);

        void update_score(Cell_type& cell_type);
    
    private:
        int score;
        int high_score;
        Character_sprites characters_sample;
};
