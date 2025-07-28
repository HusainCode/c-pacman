#ifndef PACMAN_H
#define PACMAN_H

typedef struct pacman
{
    int *x;
    int *y;
    int *dx, *dy;  // direction (pointers)
    int *direction;
    int *lives;
} Pacman;

// create pacman at a position
Pacman pacmanInit(int x, int y);

// Move pacman
void pacmanMove(Pacman *p, int dx, int dy);
// Draw pacman
void pacmanDraw(const Pacman *p);

#endif  // PACMAN_H