#include "../include/pacman.h"
#include <stdio.h>
#include <SDL2/SDL.h>



// Initialize Pac-Man at givin position
Pacman pacman_init(int x, int y){
    Pacman p = {0};
    p.x = x;
    p.y = y;
    p.lives = 3; // 3 lives just like the real game
    p.direction = 0;
    SDL_Color pacmanColor[1]; // yellow

    return p;

}

void pacmanMove(Pacman *p, int dx, int dy){
    if(!p) return;
    p->x += dx;
    p->y += dy;
}

// void pacmanDraw(const Pacman *p){
//     if(!p) return;
//     printf("PacMan is at(%d, %d)\n", p->x, p->y);
// }