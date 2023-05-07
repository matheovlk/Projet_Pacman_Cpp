#pragma once

#include "drawable.hpp"

class Score
{
    public:

        Score();

        //Score(SDL_Surface* sprites, SDL_Surface* win_surf);

        void update_score(Cell_type& cell_type);

        int get_score();
        int get_high_score();
    
    private:
        int score;
        int high_score;
        //Character_sprites characters_sample;
};