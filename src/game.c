#include <stdio.h>
#include <SDL2/SDL.h>

#include "../include/ghost.h"
#include "../include/gui.h"
#include "../include/pacman.h"

#define MAP_WIDTH 28
#define MAP_HEIGHT 31

int gameMap[MAP_HEIGHT][MAP_WIDTH]; // global map


void gameIntro();

// Initialize game state: map, score, positions, etc.
int initGameStats(void) {
    // Clear map
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            gameMap[y][x] = 0; // 0 = empty space
        }
    }

    // Set some walls, just a sample layout
    for (int x = 0; x < MAP_WIDTH; ++x) {
        gameMap[0][x] = 1;                  // top wall
        gameMap[MAP_HEIGHT - 1][x] = 1;     // bottom wall
    }

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        gameMap[y][0] = 1;                  // left wall
        gameMap[y][MAP_WIDTH - 1] = 1;      // right wall
    }

    // printf("Game initialized!\n");
    return 0; // success
}


