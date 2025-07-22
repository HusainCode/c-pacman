#include <stdio.h>
#include "../include/gui.h"

int main() {

    printf("Welcome to Pac-Man!\n");

    gui_init();

    SDL_Event event;
    int running = 1;

    // the game loop runining, till press X 
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_Delay(10); // Keep it responsive
    }

    gui_quit();
    return 0;
}