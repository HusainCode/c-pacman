#include "../include/ghost.h"
#include <SDL2/SDL.h>






void ghostInit(Ghost *ghost, int x, int y, GhostType type, GhostColor *ghostColor ) {
    ghost->x = x;
    ghost->y = y;
    ghost->dx = 0;
    ghost->dy = 0;
    ghost->isScared = false;
    ghost->respawn = false;
    
    ghostColor->red    = (SDL_Color){255, 0, 0, 255};       // [0] BLINKY - red
    ghostColor->pink   = (SDL_Color){255, 105, 180, 255};   // [1] PINKY - pink
    ghostColor->blue   = (SDL_Color){0, 0, 255, 255};       // [2] INKY - blue
    ghostColor->yellow = (SDL_Color){255, 255, 0, 255};     // [3] CLYDE - yellow
    ghostColor->scared = (SDL_Color){0, 255, 255, 255};     // [4] SCARED - cyan
 
    // Default color scheme
    switch (type)
    {
        case BLINKY:
        ghost->color = ghostColor->red;
        break;

        case PINKY:
        ghost->color = ghostColor->pink;
        break;

        case INKY:
        ghost->color = ghostColor->blue;
        break;

        case CLYDE:
        ghost->color = ghostColor->yellow;
        break;

        case SCARED:
        ghost->color = ghostColor->scared;
        break;


    }


}


void makeGhostVulnerbale(bool isScared){
  
}

int isWall(int x, int y) {
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT) {
        return 1;
    }
    return gameMap[y][x] == 1;
}

// Moves the ghost if the new position isn't a wall
void ghostMove(Ghost *g, int dx, int dy) {
    int newX = g->x + dx;
    int newY = g->y + dy;

    if (!isWall(newX, newY)) {
        g->x = newX;
        g->y = newY;
        printf("Ghost moved to (%d, %d)\n", g->x, g->y);
    } else {
    
        printf("Ghost hit a wall at (%d, %d)\n", newX, newY);
    }
}
void updateGhostTarget(Ghost *ghost, int pacmanX, 
    int pacmanY, int pacmanDX, int pacmanDY, int blinkyX, int blinkyY){

    int tagetX = pacmanX;
    int tagetY = pacmanY;

switch (ghost->type){
    case BLINKY:
    // Blinky chases pacman directly
    targetX = pacmanX;
    targetY = pacmanY;
    break;

case PINKY:
    // Pinky targets 4 titles ahead of PacMan
     targetX = pacmanX + pacmanDX * 4;
     targetY = pacmanY + pacmanDY * 4;
     break;

     case INKY:
     // Inky uses vector between Blinky and 2 tiles ahead of Pacman
     {
        int aheadX = pacmanX + pacmanDX * 2;
        int aheadY = pacmanY + pacmanDY * 2;
        tagetX = 2 * aheadX - blinkyX;
        tagetY = 2 * aheadY - blinkyY;
     }
     break;
     case CLYDE:
     // Clyde chaes when far, scatters when near
     {
        int distSq = (ghost->x - pacmanX) * (ghost->x - pacmanX) +
                     (ghost->y - pacmanY) * (ghost->  pacmanY);
        
        if (distSq > 64) // 8 tiles {
        tagetX = pacmanX;
        tagetY = pacmanY;

        } else {
            tagetX = 0;
            tagetY = 20;
        }

     }
     break;


}

}