#pragma once

constexpr float GAME_SPEED = 10;

constexpr unsigned char MAP_WIDTH = 21;
constexpr unsigned char MAP_HEIGHT = 27;

constexpr unsigned char CELL_SIZE = 32;
//x y  w h
constexpr unsigned char BASIC_SPRITE_SCALE = 2;

constexpr unsigned int MAP_SPRITE_X = 369;
constexpr unsigned int MAP_SPRITE_Y = 3;
constexpr unsigned int MAP_SPRITE_W = MAP_WIDTH * 8;
constexpr unsigned int MAP_SPRITE_H = MAP_HEIGHT * 8;
constexpr unsigned char MAP_SPRITE_SCALE = 4;

constexpr unsigned char PACGUM_SPRITE_SIZE = 2;
constexpr unsigned int PACGUM_SPRITE_X = 4;
constexpr unsigned int PACGUM_SPRITE_Y = 81;
constexpr unsigned char GUM_SPRITE_SCALE = 4;

constexpr unsigned char SUPERGUM_SPRITE_SIZE = 7;
constexpr unsigned int SUPERGUM_SPRITE_X = 9;
constexpr unsigned int SUPERGUM_SPRITE_Y = 79;

constexpr unsigned int CHARACTER_SPRITE_W = 14;
constexpr unsigned int CHARACTER_SPRITE_H = 14;

constexpr unsigned int PACMAN_SPRITE_Y = 90;
constexpr unsigned int PACMAN_ROUND_SPRITE_X = 4;
constexpr unsigned int PACMAN_RIGHT_1_SPRITE_X = 21;
constexpr unsigned int PACMAN_RIGHT_2_SPRITE_X = 34;
constexpr unsigned int PACMAN_LEFT_1_SPRITE_X = 48;
constexpr unsigned int PACMAN_LEFT_2_SPRITE_X = 61;
constexpr unsigned int PACMAN_UP_1_SPRITE_X = 76;
constexpr unsigned int PACMAN_UP_2_SPRITE_X = 93;
constexpr unsigned int PACMAN_DOWN_1_SPRITE_X = 110;
constexpr unsigned int PACMAN_DOWN_2_SPRITE_X = 127;

constexpr unsigned int BLINKY_SPRITE_Y = 124;
constexpr unsigned int PINKY_SPRITE_Y = 142;
constexpr unsigned int INKY_SPRITE_Y = 160;
constexpr unsigned int CLYDE_SPRITE_Y = 178;

constexpr unsigned int GHOST_RIGHT_1_SPRITE_X = 4;
constexpr unsigned int GHOST_RIGHT_2_SPRITE_X = GHOST_RIGHT_1_SPRITE_X + 17;
constexpr unsigned int GHOST_LEFT_1_SPRITE_X = GHOST_RIGHT_2_SPRITE_X + 17;
constexpr unsigned int GHOST_LEFT_2_SPRITE_X = GHOST_LEFT_1_SPRITE_X + 17;
constexpr unsigned int GHOST_UP_1_SPRITE_X = GHOST_LEFT_2_SPRITE_X + 17;
constexpr unsigned int GHOST_UP_2_SPRITE_X = GHOST_UP_1_SPRITE_X + 17;
constexpr unsigned int GHOST_DOWN_1_SPRITE_X = GHOST_UP_2_SPRITE_X + 17;
constexpr unsigned int GHOST_DOWN_2_SPRITE_X = GHOST_DOWN_1_SPRITE_X + 17;





// enum class is more precise than enum, avoid name conflict
enum class Cell_type
{
	Empty,
	Wall,
    Spawn,
    Gum,
    Super_gum,
};

template <typename T> struct Coordinates{ 
    T x; 
    T y;
};