#pragma once

#include <array>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>

#include "drawable.h"
#include "constants.h"

class Game
{
    public:
        
        Game(){};

        void init(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites)
        {
            std::array<std::string, MAP_HEIGHT> map_sketch = {
            "wwwwwwwwwwwwwwwwwwwwwwwwwwww",
            "w............ww............w",
            "w.wwww.wwwww.ww.wwwww.wwww.w",
            "wowwww.wwwww.ww.wwwww.wwwwow",
            "w.wwww.wwwww.ww.wwwww.wwww.w",
            "w..........................w",
            "w.wwww.ww.wwwwwwww.ww.wwww.w",
            "w.wwww.ww.wwwwwwww.ww.wwww.w",
            "w......ww....ww....ww......w",
            "wwwwww.wwwww ww wwwww.wwwwww",
            "wwwwww.wwwww ww wwwww.wwwwww",
            "wwwwww.ww          ww.wwwwww",
            "wwwwww.ww wwwwwwww ww.wwwwww",
            "wwwwww.ww w      w ww.wwwwww",
            "      .   w      w   .      ",
            "wwwwww.ww w      w ww.wwwwww",
            "wwwwww.ww wwwwwwww ww.wwwwww",
            "wwwwww.ww          ww.wwwwww",
            "wwwwww.ww wwwwwwww ww.wwwwww",
            "wwwwww.ww wwwwwwww ww.wwwwww",
            "w............ww............w",
            "w.wwww.wwwww.ww.wwwww.wwww.w",
            "w.wwww.wwwww.ww.wwwww.wwww.w",
            "wo..ww....... P.......ww..ow",
            "www.ww.wwwww.ww.wwwww.ww.www",
            "www.ww.wwwww.ww.wwwww.ww.www"
            "w......ww....ww....ww......w",
            "w.wwwwwwwwww.ww.wwwwwwwwww.w",
            "w.wwwwwwwwww.ww.wwwwwwwwww.w",
            "w..........................w",
            "wwwwwwwwwwwwwwwwwwwwwwwwwwww"

        };
            SDL_Event event;
            bool quit = false;

            std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> board{};

            board = sketch_to_board(map_sketch);

            Drawable map{sprites, win_surf, map_sprite_loc, MAP_SPRITE_SCALE, false};
            Drawable pacman{sprites, win_surf, { PACMAN_SPRITE_X ,PACMAN_SPRITE_Y, PACMAN_SPRITE_W, PACMAN_SPRITE_H }, PACMAN_SPRITE_SCALE};

            while (!quit)
            {
                SDL_Event event;
                while (!quit && SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    default: break;
                    }
                }

                // Gestion du clavier        
                int nbk;
                const Uint8* keys = SDL_GetKeyboardState(&nbk);
                if (keys[SDL_SCANCODE_ESCAPE])
                    quit = true;

                map.draw(0, 0);

                pacman.draw(35, 35);


                // AFFICHAGE
                SDL_UpdateWindowSurface(pWindow); 
                // LIMITE A 60 FPS
                SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
            }
        }

    private:
        SDL_Rect map_sprite_loc = { MAP_SPRITE_X ,MAP_SPRITE_Y, MAP_SPRITE_W, MAP_SPRITE_H }; // x,y, w,h (0,0) en haut a gauche
        std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> sketch_to_board(std::array<std::string, MAP_HEIGHT>&);

};