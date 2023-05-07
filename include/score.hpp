#pragma once

#include "drawable.hpp"

class Score
{
    public:

        Score();

        void update_score(Cell_type& cell_type);

        int get_score();

        int get_high_score();

        void reset_score();
    
    private:
        int score;
        int high_score;
};
