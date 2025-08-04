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

// Check if pellet is power or reguluar
int isPelletAt(int x, int y) {
    return (gameMap[y][x] == TITLE_PELLET || TITLE_POWER_PELLET);

}


// Collects a pellet at the given tile and updates scores/state 
void collect_pellet(int x, int y){
    // || gameMap[y][x] == TITLE_POWER_PELLET
    if(gameMap[y][x] == TITLE_PELLET ){
        gameMap[y][x] == TITLE_EMPTY;
        gameScore += 10; // regular pellet
        pelltesRemaining --;
    }
    else if (gameMap[y][x] == TITLE_POWER_PELLET){
        gameMap[y][x] == TITLE_EMPTY;
        gameScore +=50;
        powerPelltesRemaining--;
         // TODO: trigger power-up state for ghosts
    }

}

void resetPellets(void){
    if(powerPelltesRemaining == 0 && pelltesRemaining == 0){
        for(int y = 0; y < MAP_HEIGHT; y++){
          // STOPED HERE
        }
    }
}