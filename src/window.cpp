#include "window.hpp"
#include "constants.hpp"

int Window::init(SDL_Window* &pWindow, SDL_Surface* &win_surf, SDL_Surface* &sprites)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return 1;
    }
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);
    
    // fond de la fenetre  
    Uint32 color = SDL_MapRGB(win_surf->format,0,0,0);
    SDL_FillRect(win_surf,NULL, color);

    sprites = SDL_LoadBMP("./assets/pacman_sprites.bmp");
    return 0;
}

void Window::run_game()
{
    Game game{pWindow, win_surf, sprites};
    game.init();
    SDL_Quit(); // ON SORT
}

int Window::start()
{

    if (init(pWindow, win_surf, sprites) == 1)
    {
        std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
        return 1;
    }
    run_game();
    return 0;
}