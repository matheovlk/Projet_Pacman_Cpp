#pragma once

constexpr float GAME_SPEED = 0.5;


constexpr unsigned char MAP_WIDTH = 21;
constexpr unsigned char MAP_HEIGHT = 27;

constexpr unsigned char CELL_SIZE = 8;
//x y  w h
constexpr unsigned char BASIC_SPRITE_SCALE = 2;

constexpr unsigned int MAP_SPRITE_X = 369;
constexpr unsigned int MAP_SPRITE_Y = 3;
constexpr unsigned int MAP_SPRITE_W = MAP_WIDTH * CELL_SIZE;
constexpr unsigned int MAP_SPRITE_H = MAP_HEIGHT * CELL_SIZE;
constexpr unsigned char MAP_SPRITE_SCALE = 4;

constexpr unsigned int PACMAN_SPRITE_X = 21;
constexpr unsigned int PACMAN_SPRITE_Y = 90;
constexpr unsigned int PACMAN_SPRITE_W = 14;
constexpr unsigned int PACMAN_SPRITE_H = 14;

enum Cell
{
	Empty,
	Wall,
    Gum,
    Super_gum,
};
