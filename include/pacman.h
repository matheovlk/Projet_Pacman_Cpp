#ifndef __PACAMAN_H__
#define __PACAMAN_H__

#include <SDL.h>
#include <iostream>

#include "game.h"

class Pacman
{

    public:
    
        Pacman(){};

        SDL_Window* pWindow = nullptr;
        SDL_Surface* win_surf = nullptr;
        SDL_Surface* plancheSprites = nullptr;
        int* count;


        int start()
        {

            if (SDL_Init(SDL_INIT_VIDEO) != 0 )
            {
                std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
                return 1;
            }

            init();
            Game game;
            // BOUCLE PRINCIPALE
            bool quit = false;
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
                if (keys[SDL_SCANCODE_LEFT])
                    puts("LEFT");
                if (keys[SDL_SCANCODE_RIGHT])
                    puts("RIGHT");

                // AFFICHAGE
                game.draw(pWindow, win_surf, plancheSprites, count);
                SDL_UpdateWindowSurface(pWindow); 
                // LIMITE A 60 FPS
                SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
            }
            SDL_Quit(); // ON SORT
            return 0;
        }

    private:
        void init()
        {
            pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
            win_surf = SDL_GetWindowSurface(pWindow);
            plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
            *count = 0;
        }
};

#endif