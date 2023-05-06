#pragma once

#include "drawable.hpp"

class Score
{
    public:

        Score(){
            score = 0;
            high_score = 0;
        };
        void update_score(Cell_type cell_type);

        int score;
        int high_score;
};
