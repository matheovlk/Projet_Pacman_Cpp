#pragma once

#include "drawable.h"
#include "constants.h"

class Movable: public Drawable
{
    public:
        Movable(){};

        void set_position(unsigned int x, unsigned int y);

    protected:
        unsigned int x_;
        unsigned int y_;
};