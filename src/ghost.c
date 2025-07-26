#include "../include/ghost.h"
#include <SDL2/SDL.h>

typedef enum { BLINKY, PINKY, INKY, CLYDE } GhostType; // ghost type

Ghost ghostInit(int x, int y) {
    Ghost ghost;
    ghost.x = x;
    ghost.y = y;
    ghost.dx = 0;
    ghost.dy = 0;
    ghost.isScared = false;
    ghost.respawn = false;
    GhostType type;

    // Default color scheme
    ghost.colors[0] = (SDL_Color){255, 0, 0, 255};     // red
    ghost.colors[1] = (SDL_Color){255, 105, 180, 255}; // pink
    ghost.colors[2] = (SDL_Color){255, 255, 0, 255};   // yellow
    ghost.colors[3] = (SDL_Color){0, 255, 0, 255};     // green
    ghost.colors[4] = (SDL_Color){0,0,255,255};  // originalColor

    return ghost;
}


void makeGhostVulnerbale(bool isScared){
    ghost.isScared = isScared;
    ghost.color = isScared ? (SDL_Color){0,0,255,255}: ghost->colors[4];
}

void ghostMove(int dx, int dy){

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