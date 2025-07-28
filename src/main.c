#include <stdio.h>
#include "../include/gui.h"
#include "../include/pacman.h"
#include "../include/gui.h"


int main() {

    printf("Welcome to Pac-Man!\n");

    guiInit();

    SDL_Event event = {0};
    Pacman pacmanDefaultPosition = {0}; // defualt psotion
    Pacman *pacman = &pacmanDefaultPosition;

    int running = 1;

    // the game loop runining, till press X 
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }

            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_UP:
                    pacmanMove(&pacman, 0 , -1);
                    break;

                    case SDLK_DOWN:
                    pacmanMove(&pacman, 0,1);
                    break;

                    case SDLK_LEFT:
                    pacmanMove(&pacman, -1, 0);
                    break;

                    case SDLK_RIGHT:
                    pacmanMove(&pacman, 1, 0);
                    break;

                }
                
            }
        }

        SDL_Delay(10); // Keep it responsive
    }

    gui_quit();
    return 0;
}