#pragma once

constexpr float GAME_SPEED = 10;

constexpr unsigned char MAP_WIDTH = 21;
constexpr unsigned char MAP_HEIGHT = 27;

constexpr unsigned char OFFSET = 75;
constexpr unsigned char WORD_OFFSET = 0;
constexpr unsigned char CELL_SIZE = 32;
//x y  w h
constexpr unsigned char BASIC_SPRITE_SCALE = 2;

constexpr unsigned int WINDOW_WIDTH = 672;
constexpr unsigned int WINDOW_HEIGHT = 1000;

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

constexpr unsigned char FRUIT_SPRITE_SIZE = 14;

constexpr unsigned int CHERRY_SPRITE_X = 290;
constexpr unsigned int CHERRY_SPRITE_Y = 238;
constexpr unsigned int STRAWBERRY_SPRITE_X = 307;
constexpr unsigned int STRAWBERRY_SPRITE_Y = 238;
constexpr unsigned int ORANGE_SPRITE_X = 322;
constexpr unsigned int ORANGE_SPRITE_Y = 238;
constexpr unsigned int APPLE_SPRITE_X = 338;
constexpr unsigned int APPLE_SPRITE_Y = 238;
constexpr unsigned int MELON_SPRITE_X = 355;
constexpr unsigned int MELON_SPRITE_Y = 238;
constexpr unsigned int GALAXIAN_SPRITE_X = 371;
constexpr unsigned int GALAXIAN_SPRITE_Y = 238;
constexpr unsigned int BELL_SPRITE_X = 387;
constexpr unsigned int BELL_SPRITE_Y = 238;
constexpr unsigned int KEY_SPRITE_X = 402;
constexpr unsigned int KEY_SPRITE_Y = 238;

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

constexpr unsigned int CHARACTER_SIZE = 8;
constexpr unsigned int CHARACTER_0_9_Y = 53;
constexpr unsigned int CHARACTER_A_O_Y = 61;
constexpr unsigned int CHARACTER_P_Z_Y = 69;
constexpr unsigned int CHARACTER_0SPACEP_X = 4;
constexpr unsigned int CHARACTER_1AQ_X = CHARACTER_0SPACEP_X + 8;
constexpr unsigned int CHARACTER_2BR_X = CHARACTER_1AQ_X + 8;
constexpr unsigned int CHARACTER_3CS_X = CHARACTER_2BR_X + 8;
constexpr unsigned int CHARACTER_4DT_X = CHARACTER_3CS_X + 8;
constexpr unsigned int CHARACTER_5EU_X = CHARACTER_4DT_X + 8;
constexpr unsigned int CHARACTER_6FV_X = CHARACTER_5EU_X + 8;
constexpr unsigned int CHARACTER_7GW_X = CHARACTER_6FV_X + 8;
constexpr unsigned int CHARACTER_8HX_X = CHARACTER_7GW_X + 8;
constexpr unsigned int CHARACTER_9IY_X = CHARACTER_8HX_X + 8;
constexpr unsigned int CHARACTER_JZ_X = CHARACTER_9IY_X + 8;
constexpr unsigned int CHARACTER_K_X = CHARACTER_JZ_X + 8;
constexpr unsigned int CHARACTER_EXCLAL_X = CHARACTER_K_X + 8;
constexpr unsigned int CHARACTER_M_X = CHARACTER_EXCLAL_X + 8;
constexpr unsigned int CHARACTER_N_X = CHARACTER_M_X + 8;
constexpr unsigned int CHARACTER_O_X = CHARACTER_N_X + 8;

constexpr unsigned int SCALED_CHARACTER = CHARACTER_SIZE * BASIC_SPRITE_SCALE;
// The score can be maximum 999990
constexpr unsigned int LENGTH_SCORE = SCALED_CHARACTER * 6;
constexpr unsigned int SCORE_BASIC_OFFSET = 30;
constexpr unsigned int HIGH_SCORE_BASIC_OFFSET = 250;





// enum class is more precise than enum, avoid name conflict
enum class Cell_type
{
	Empty,
	Wall,
    Spawn,
    Gum,
    Super_gum,
    Fruit,
    Door
};

template <typename T> struct Coordinates{ 
    T x; 
    T y;
};