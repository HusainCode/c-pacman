#include <SDL2/SDL.h>
#include "../include/logger.h" // For LOG_ERROR, LOG_INFO


static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

bool guiInit(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        LOG_ERROR("Failed to initialize SDL video: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
        "Pacman",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        LOG_ERROR("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        LOG_ERROR("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    LOG_INFO("GUI initialized successfully");
    return true;
}

void guiPresent(void) {
    SDL_RenderPresent(renderer);
}

void guiClear(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);
}

void guiQuit(void) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    SDL_Quit();
    LOG_INFO("GUI cleaned up and SDL quit");
}

SDL_Renderer *guiGetRenderer(void) {
    return renderer;
}
