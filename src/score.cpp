#include "score.hpp"
#include <vector>

void Score::update_score(Cell_type cell_type)
{
    if (cell_type == Cell_type::Gum)
        score += 10;
    if (cell_type == Cell_type::Super_gum)
        score += 50;
    if (score > high_score)
        high_score = score;


    // Print the new score on the map
    int score_to_print = score;
    std::vector<SDL_Rect> score_texture;
    do {
        switch (score_to_print % 10)
        {
        case 0:
            // score_texture.push_back(ScoreCoords.ZERO);
            break;
        
        default:
            break;
        }
        score_to_print = floor(score_to_print / 10);
    } while (score_to_print > 10);

    // inverser le score



    Drawable zero{sprites, win_surf, map_sprite_loc, MAP_SPRITE_SCALE};


    // 0: 4-11
    //    53-60

    

    
}