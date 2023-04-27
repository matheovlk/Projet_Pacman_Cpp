#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>

#include "drawable.h"

class Game
{
    public:
        
        Game(){};

        void init(SDL_Window* pWindow, SDL_Surface* win_surf, SDL_Surface* sprites)
        {
            SDL_Event event;
            bool quit = false;
            Drawable map{sprites, win_surf, map_sprite_loc, 4, false};
            Drawable pacman{sprites, win_surf, { 21 ,90, 13,14 }, 4};

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

                pacman.draw(0, 0);


                // AFFICHAGE
                SDL_UpdateWindowSurface(pWindow); 
                // LIMITE A 60 FPS
                SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
            }
        }

    private:
        SDL_Rect map_sprite_loc = { 370,4, 167,214 }; // x,y, w,h (0,0) en haut a gauche

};

#endif
