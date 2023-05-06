#pragma once

#include <vector>

#include "drawable.hpp"
#include "constants.hpp"


// enum class is more precise than enum, avoid name conflict
enum class Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
};

class Movable: public Drawable
{
    public:
    
        Movable(){};

        void set_position(const unsigned int& x, const unsigned int& y);

        void draw(const bool& update_anim);

    protected:
        Coordinates<int> position;
        Direction direction_;
        std::vector<SDL_Rect> animation_textures;
        unsigned char animation_index = 0;
        unsigned char nb_anim_frames;
};