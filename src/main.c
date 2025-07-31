#include <stdio.h>
#include "../include/gui.h"
#include "../include/pacman.h"
#include <SDL2/SDL.h>

SDL_Event event = {0};
Pacman pacmanDefaultPosition = {0}; // default position
Pacman *pacman = &pacmanDefaultPosition;

void runGame();
void initEverything(void)

int main() {
    printf("Welcome to Pac-Man!\n");

    guiInit();
    runGame();

    return 0;
}


void runGame() {
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        pacmanMove(&pacman, 0, -1);
                        break;
                    case SDLK_DOWN:
                        pacmanMove(&pacman, 0, 1);
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

        SDL_Delay(10);
    }

    gui_quit();
}


void initEverything(void){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    createWindow();
    drawPacman();
    drawGhosts();
    initGameState();
    renderGameState();
    handleInput();
    checkGameCollisions();
    restGame();
}