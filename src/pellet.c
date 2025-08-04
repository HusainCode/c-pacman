#include "pellet.h"
#include "../include/game.h"
#include <stdbool.h>



void spwan_pellet(int x, int y){
    if(gameMap[y][x] == TITLE_EMPTY){
        gameMap[y][x] = TITLE_PELLET;
        pelltesRemaining++;
    }
}


void spawnPowerPellet(int x, int y){
    if(gameMap[y][x] == TITLE_EMPTY){
        gameMap[y][x] == TITLE_POWER_PELLET;
        powerPelltesRemaining++;
    }
}
int isPelletAt(int x, int y);

void collect_pellet(int x, int y);