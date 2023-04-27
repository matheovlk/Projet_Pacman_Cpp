#pragma once

constexpr unsigned char MAP_WIDTH = 28;
constexpr unsigned char MAP_HEIGHT = 31;

//x y  w h
constexpr unsigned int MAP_SPRITE_X = 370;
constexpr unsigned int MAP_SPRITE_Y = 4;
constexpr unsigned int MAP_SPRITE_W = 167;
constexpr unsigned int MAP_SPRITE_H = 214;
constexpr unsigned int MAP_SPRITE_SCALE = 4;

constexpr unsigned int PACMAN_SPRITE_X = 21;
constexpr unsigned int PACMAN_SPRITE_Y = 90;
constexpr unsigned int PACMAN_SPRITE_W = 13;
constexpr unsigned int PACMAN_SPRITE_H = 14;
constexpr unsigned int PACMAN_SPRITE_SCALE = 2;

enum Cell
{
	Empty,
	Wall,
    Gum,
    Super_gum,
};
