#pragma once

#include "../include/game.h"

extern int map[MAP_HEIGHT][MAP_WIDTH]; 


void spwanPellet(int x, int y); // add pellte to map

int isPelletAt(int x, int y); // checl for pellet at tile

void collectPellet(int x, int y); //consume pellter at tile
