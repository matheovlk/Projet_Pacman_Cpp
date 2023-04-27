#include "window.h"

int Window::init(SDL_Window* &pWindow, SDL_Surface* &win_surf, SDL_Surface* &sprites)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return 1;
    }
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);
    
    // fond de la fenetre  
    Uint32 color = SDL_MapRGB(win_surf->format,120,0,100); 
    SDL_FillRect(win_surf,NULL, color);

    sprites = SDL_LoadBMP("./pacman_sprites.bmp");
    return 0;
}

void Window::run_game()
{
    Game game;
    game.init(pWindow, win_surf, sprites);
    SDL_Quit(); // ON SORT
}