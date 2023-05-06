#include "score.hpp"
#include <vector>
#include <iostream>

void Score::update_score(Cell_type& cell_type)
{
    if (cell_type == Cell_type::Gum)
        score += 10;
    if (cell_type == Cell_type::Super_gum)
        score += 50;
    if (score > high_score)
        high_score = score;


    // Print the new score on the map
    int score_to_print = score;
    //std::vector<std::vector<SDL_Rect>> score_texture;     push back
    int i = 0;
    do {
        characters_sample.set_sprite_coord(characters_sample.get_specific_texture(score_to_print % 10));
        characters_sample.draw(i*15, 0);
        score_to_print = floor(score_to_print / 10);
        i++;
    } while (score_to_print > 10);

    // inverser le score   
}

Score::Score(Character characters_sample)
{
    score = 0;
    high_score = 0;
    this->characters_sample = characters_sample;        
}