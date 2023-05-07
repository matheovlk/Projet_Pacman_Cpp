#include "word.hpp"

// for strings
void Word::set_word(std::string word)
{
    std::vector<SDL_Rect> word_sprites;

    for (char c : word)
    {
        c = toupper(c);
        if (c >= 'A' && c <= 'Z')
        {
            int index = c - 'A';
            word_sprites.push_back(this->letter_sprites[index]);
        }
        if (c == ' ')
        {
            word_sprites.push_back(this->space_sprite);  
        }
        if (c == '!')
        {
            word_sprites.push_back(this->exclamation_sprite);

        }
        if (c >= '0' && c <= '9')
        {
            int index = c - '0';
            word_sprites.push_back(this->number_sprites[index]);
        }
    }
    
    this->word_sprites = word_sprites;
}

void Word::draw(int x, int y)
{
    int current_x = x;

    for (auto& sprite : this->word_sprites)
    {
        this->sprite_coord_ = sprite;
        Drawable::draw(current_x, y);
        current_x += CHARACTER_SIZE * BASIC_SPRITE_SCALE;
    }
}

void Word::set_word(int number)
{
    std::string word = std::to_string(number);
    set_word(word);
}
