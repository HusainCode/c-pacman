#include <SDL2/SDL.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

void guiInit(){
    SDL_init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Pacman",
         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600 , 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void guiPresent(){
    SDL_RenderPresent(renderer);
}

void gui_quit(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

