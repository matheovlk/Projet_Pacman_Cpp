#pragma once

#include "drawable.hpp"
#include "word.hpp"

class Score
{
    public:

        Score();

        Score(SDL_Surface* win_surf, SDL_Surface* sprites);

        void update_score(Cell_type& cell_type);
        void print_scores();
        void print_basic_scores();
        int get_score();
        int get_high_score();
        void reset_score();
    
    private:
        int score;
        int high_score;
        SDL_Surface* win_surf;
        SDL_Surface* sprites;
        Word high_score_word;
	    Word score_sprite;
	    Word high_score_sprite;
};
