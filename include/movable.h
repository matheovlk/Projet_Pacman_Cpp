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

        void set_position(int x, int y);

        void draw(unsigned char update_anim);

    protected:
        int x_;
        int y_;
        Direction direction_;
        std::vector<SDL_Rect> animation_textures;
        unsigned char animation_index = 0;
        unsigned char nb_anim_frames;
};