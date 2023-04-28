#pragma once

#include <array>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <algorithm>

#include "constants.h"

#include "drawable.h"
#include "pacman.h"

class Game
{
    public:
        
        Game(){};

        void init(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites)
        {
            std::array<std::string, MAP_HEIGHT> map_sketch = {
            "wwwwwwwwwwwwwwwwwwwww",
            "w.........w.........w",
            "w.www.www.w.www.www.w",
            "wowww.www.w.www.wwwow",
            "w.www.www.w.www.www.w",
            "w...................w",
            "w.www.w.wwwww.w.www.w",
            "w.www.w.wwwww.w.www.w",
            "w.....w...w...w.....w",
            "wwwww.www w www.wwwww",
            "wwwww.w       w.wwwww",
            "wwwww.w wwwww w.wwwww",
            "wwwww.w wwwww w.wwwww",
            "     .  wwwww  .     ",
            "wwwww.w wwwww w.wwwww",
            "wwwww.w       w.wwwww",
            "wwwww.w wwwww w.wwwww",
            "wwwww.w wwwww w.wwwww",
            "w.........w.........w",
            "w.www.www.w.www.www.w",
            "wo..w.....P.....w..ow",
            "www.w.w.wwwww.w.w.www",
            "www.w.w.wwwww.w.w.www",
            "w.....w...w...w.....w",
            "w.wwwwwww.w.wwwwwww.w",
            "w...................w",
            "wwwwwwwwwwwwwwwwwwwww",


            };
            SDL_Event event;
            bool quit = false;

            std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> board{};
            Pacman pacman{sprites, win_surf};

            board = sketch_to_board(map_sketch, pacman);

            Drawable map{sprites, win_surf, map_sprite_loc, MAP_SPRITE_SCALE, false};

            while (!quit)
            {
                Uint64 start = SDL_GetPerformanceCounter();

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

                
                   
                const Uint8 *keys = SDL_GetKeyboardState(NULL);
                if (keys[SDL_SCANCODE_ESCAPE])
                    quit = true;
                if (keys[SDL_SCANCODE_LEFT])
                {
                    pacman.set_direction(LEFT, board);
                }
                if (keys[SDL_SCANCODE_RIGHT])
                {
                    pacman.set_direction(RIGHT, board);
                }
                if (keys[SDL_SCANCODE_UP])
                {
                    pacman.set_direction(UP, board);
                }
                if (keys[SDL_SCANCODE_DOWN])
                {
                    pacman.set_direction(DOWN, board);
                }
                map.draw(0, 0);

                pacman.move(board);
                pacman.draw();


                // AFFICHAGE
                SDL_UpdateWindowSurface(pWindow); 

                //30 FPS
                Uint64 end = SDL_GetPerformanceCounter();
                float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
                SDL_Delay(std::max(floor(33.333f / GAME_SPEED - elapsedMS), 0.0f));
            }
        }

    private:
        SDL_Rect map_sprite_loc = { MAP_SPRITE_X ,MAP_SPRITE_Y, MAP_SPRITE_W, MAP_SPRITE_H }; // x,y, w,h (0,0) en haut a gauche
        std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> sketch_to_board(std::array<std::string, MAP_HEIGHT>&, Pacman&);

};