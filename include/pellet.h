#pragma once

#include "../include/game.h"

#define TITLE_EMPTY 0 // nothing there
#define TITLE_WALL 1 // solid wall
#define TITLE_PELLET 2 // normal pellet
#define TITLE_POWER_PELLET 3 // power-up pellet

extern int map[MAP_HEIGHT][MAP_WIDTH]; 
extern int score;
extern int pelltesRemaining;

void spwanPellet(int x, int y); // add pellte to map

int isPelletAt(int x, int y); // checl for pellet at tile

void collectPellet(int x, int y); //consume pellter at tile

void resetPellets (); // when starting a new game // STOPPED HERE
