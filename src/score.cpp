#include "score.hpp"
#include <vector>
#include <iostream>

Score::Score()
{
    this->score = 0;
    this->high_score = 0;
}

Score::Score(SDL_Surface* sprites, SDL_Surface* win_surf)
{
    this->score = 0;
    this->high_score = 0;
    this->win_surf = win_surf;
    this->sprites = sprites;
    high_score_word = Word{sprites, win_surf};
	score_sprite = {sprites, win_surf};
	high_score_sprite = {sprites, win_surf};
}

int Score::get_score()
{
    return this->score;
}

int Score::get_high_score()
{
    return this->high_score;
}

void Score::print_basic_scores()
{
    this->high_score_word.set_word("HIGH SCORE");
	this->high_score_word.draw(HIGH_SCORE_BASIC_OFFSET, 10);
}

void Score::print_scores()
{
    score_sprite.set_word(this->score);
    // We want the last number of the score to be always on the same place.
    // When the score length increments (90 to 100 for ex), the zero stays at the same place
    // The bigger the score is, the smaller the offset is
    this->score_sprite.draw(SCORE_BASIC_OFFSET+LENGTH_SCORE-SCALED_CHARACTER*(std::to_string(this->score).length()), 30);

    this->score_sprite.set_word(this->high_score);
    // Same logic as the score
    this->score_sprite.draw(HIGH_SCORE_BASIC_OFFSET+LENGTH_SCORE-SCALED_CHARACTER*(std::to_string(this->high_score).length()-4), 30);
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

void Score::reset_score()
{
    this->score = 0;
    score_sprite.set_word("      ");
    this->score_sprite.draw(SCORE_BASIC_OFFSET+LENGTH_SCORE-SCALED_CHARACTER*(std::to_string(999999).length()), 30);
    // We want the last number of the score to be always on the same place.
    // When the score length increments (90 to 100 for ex), the zero stays at the same place
    // The bigger the score is, the smaller the offset is
    score_sprite.set_word(this->score);
    this->score_sprite.draw(SCORE_BASIC_OFFSET+LENGTH_SCORE-SCALED_CHARACTER*(std::to_string(this->score).length()), 30);
}
