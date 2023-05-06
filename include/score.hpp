#pragma once

#include "drawable.hpp"
#include "character.hpp"

class Score
{
    public:

        Score(){};

        Score(Character characters_sample);

        void update_score(Cell_type& cell_type);

        int score;
        int high_score;
        Character characters_sample;
};
