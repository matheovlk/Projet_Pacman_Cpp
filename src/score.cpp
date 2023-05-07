#include "score.hpp"
#include <vector>
#include <iostream>

Score::Score()
{
    this->score = 0;
    this->high_score = 0;
}

int Score::get_score()
{
    return this->score;
}

int Score::get_high_score()
{
    return this->high_score;
}

void Score::reset_score()
{
    this->score = 0;
}


void Score::update_score(Cell_type& cell_type)
{
    if (cell_type == Cell_type::Gum)
        this->score += 10;
    if (cell_type == Cell_type::Super_gum)
        this->score += 50;
    if (cell_type == Cell_type::Fruit)
        this->score += 500;
    if (score > high_score)
        this->high_score = score;
}
