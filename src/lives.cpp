#include "lives.hpp"

Lives::Lives(SDL_Surface* sprites,SDL_Surface* win_surf)
{
    for (int i = 0; i < this->lives; i++)
    {
        this->lives_drawables.push_back(Drawable{sprites, win_surf, life_sprite, BASIC_SPRITE_SCALE, false, FOOTER_OFFSET});
    } 
}

void Lives::remove_life()
{
    this->lives --;
    lives_drawables[lives].set_sprite(empty_sprite);
}

void Lives::restore_lives(){
    this->lives = max_lives;
    for (int i = 0; i < this->lives; i++)
    {
        this->lives_drawables[i].set_sprite(life_sprite);
    }
}

bool Lives::game_over()
{
    return lives <= 0;
}

void Lives::draw_lives()
{
    for (int i = 0; i < lives_drawables.size(); i++) {
        lives_drawables[i].draw(i * CHARACTER_SPRITE_W * BASIC_SPRITE_SCALE + i * 10 + 50, 10 );
    }
}
