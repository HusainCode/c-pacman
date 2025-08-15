#include "../include/pacman.h"
#include <stdio.h>
#include <SDL2/SDL.h>

// Initialize Pac-Man at given position
Pacman pacman_init(int x, int y) {
    Pacman p = {0};
    p.x = x;
    p.y = y;
    p.lives = 3; // 3 lives just like the real game
    p.direction = 0;
    p.color.r = 255; // yellow
    p.color.g = 255;
    p.color.b = 0;
    p.color.a = 255;
    return p;
}

void pacmanMove(Pacman *p, int dx, int dy) {
    if (!p) return;
    p->x += dx;
    p->y += dy;
}

void pacmanDraw(const Pacman *p, SDL_Renderer *renderer, int size) {
    if (!p || !renderer) return;

    SDL_SetRenderDrawColor(renderer, p->color.r, p->color.g, p->color.b, p->color.a);

     
    SDL_Rect rect = { p->x, p->y, size, size };
    SDL_RenderFillRect(renderer, &rect);
}
