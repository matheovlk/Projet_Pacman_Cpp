#pragma once

#include <vector>
#include <map>
#include <memory>
#include "drawable.hpp"
#include "constants.hpp"
#include "cell.hpp"

using Board_cells = std::array<std::array<std::unique_ptr<Cell>, MAP_HEIGHT>, MAP_WIDTH>;

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

        virtual void move(Board_cells& );

    protected:
        Coordinates<int> position;
        Direction direction_;
        std::vector<SDL_Rect> current_texture;
        std::map<Direction ,std::vector<SDL_Rect>> animation_textures;
        unsigned char animation_index = 0;
        unsigned char nb_anim_frames;
};