# include "pacman.hpp"

Pacman::Pacman(SDL_Surface* sprites,SDL_Surface* win_surf)
{
    sprites_ = sprites;
    transparent_ = true;
    win_surf_ = win_surf;
    sprite_coord_ = SDL_Rect {PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H};
    pacman_textures =
    {{Direction::RIGHT, 
        {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_RIGHT_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_RIGHT_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
    {Direction::LEFT, 
        {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_LEFT_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_LEFT_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
    {Direction::UP, 
        {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_UP_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_UP_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}},
    {Direction::DOWN, 
        {{PACMAN_ROUND_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_DOWN_1_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H},
        {PACMAN_DOWN_2_SPRITE_X, PACMAN_SPRITE_Y, CHARACTER_SPRITE_W, CHARACTER_SPRITE_H}}}
    
    };
    direction_ = Direction::RIGHT;
    animation_textures = pacman_textures.find(direction_)->second;
    sprite_coord_ = animation_textures[0];
    nb_anim_frames = 3;
    scale_ = BASIC_SPRITE_SCALE;
    transparent_ = true;
}

void Pacman::set_direction(const Direction direction,const Board_cells& board)
{

    const unsigned char half_cell_size = CELL_SIZE / 2;

    switch(direction)
    {
        case Direction::LEFT:
        {
            if
            (
                board[static_cast<int>(floor((position.x - (half_cell_size + 1)) / CELL_SIZE)) % MAP_WIDTH][floor(position.y / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.y % CELL_SIZE == half_cell_size
            )
            {
                direction_ = Direction::LEFT;
                animation_textures = pacman_textures.find(Direction::LEFT)->second;

            }
            break;
        }
        case Direction::RIGHT:
        {
            if
            (
                board[static_cast<int>(floor((position.x + half_cell_size) / (CELL_SIZE))) % MAP_WIDTH][floor(position.y / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.y % CELL_SIZE == half_cell_size
            )
            {
                direction_ = Direction::RIGHT;
                animation_textures = pacman_textures.find(Direction::RIGHT)->second;
            }
            break;
        }
        case Direction::UP:
        {
            if
            (
                board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.x % CELL_SIZE == half_cell_size
            )
            {
                direction_ = Direction::UP;
                animation_textures = pacman_textures.find(Direction::UP)->second;
            }
            break;
        }
        case Direction::DOWN:
        {
            if
            (
                board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y + half_cell_size) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.x % CELL_SIZE == half_cell_size
            )
            {
                direction_ = Direction::DOWN;
                animation_textures = pacman_textures.find(Direction::DOWN)->second;
            }
            break;
        }
    }
}

void Pacman::move(Board_cells& board)
{
    const unsigned char half_cell_size = CELL_SIZE / 2;

    switch(direction_)
    {
        case Direction::LEFT:
        {
            // if in left tunnel
            if (position.x == 0)
                position.x = MAP_WIDTH * CELL_SIZE;
            //if near left tunnel
            else if (position.x <= half_cell_size)
                position.x --;
            else if
            (
                board[floor((position.x - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))][floor(position.y / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.y % CELL_SIZE == half_cell_size
            )
                position.x --;
            break;
        }
        case Direction::RIGHT:
        {
            // if in left tunnel
            if (position.x == MAP_WIDTH * CELL_SIZE)
                position.x = 0;
            // near left tunnel
            else if (floor(position.x / CELL_SIZE + 1) == MAP_WIDTH && position.x + half_cell_size > MAP_WIDTH)
                position.x ++;
            else if
            (
                board[floor((position.x + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))][floor(position.y / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.y % CELL_SIZE == half_cell_size
            )
                position.x ++;
            break;
        }
        case Direction::UP:
        {
            if
            (
                board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y - (half_cell_size + 1)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.x % CELL_SIZE == half_cell_size
            )
                position.y --;
            break;
        }
        case Direction::DOWN:
        {
            if
            (
                board[floor(position.x / static_cast<unsigned int>(CELL_SIZE))][floor((position.y + (half_cell_size)) / static_cast<unsigned int>(CELL_SIZE))]->get_pac_can_pass() && \
                position.x % CELL_SIZE == half_cell_size
            )
                position.y ++;
            break;
        }
    }

}

Coordinates<unsigned char> Pacman::get_position_on_map()
{

    unsigned char x_on_board = position.x / CELL_SIZE;
    unsigned char y_on_board = position.y / CELL_SIZE;
    return {x_on_board, y_on_board};

}
 