#pragma once

#include "../include/game.h"
#include <stdbool.h>

#define TITLE_EMPTY 0 // nothing there
#define TITLE_WALL 1 // solid wall
#define TITLE_PELLET 2 // normal pellet
#define TITLE_POWER_PELLET 3 // power-up pellet


// Global pellte state
extern int map[MAP_HEIGHT][MAP_WIDTH]; // Game tilemap
extern int score;                      // Player score
extern int pelltesRemaining;          // Remaining pellets on the map
extern int powerPelltesRemaining;
// Pellet operations 
// Pellet lifecycle
void spawnPellet(int x, int y);
void spawnPowerPellet(int x, int y);
void collectPellet(int x, int y);
void resetPellets(void); 

// Queries
int  isPelletAt(int x, int y);
int  isPowerPelletAt(int x, int y);
bool allPelletsCollected(void);
