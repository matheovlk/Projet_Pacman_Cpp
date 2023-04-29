#pragma once

#include <vector>

#include "drawable.h"
#include "constants.h"

enum Direction
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

        void set_position(unsigned int x, unsigned int y);

        void draw(unsigned char update_anim);

    protected:
        unsigned int x_;
        unsigned int y_;
        Direction direction_;
        std::vector<SDL_Rect> animation_textures;
        unsigned char animation_index = 0;
        unsigned char nb_anim_frames;
};