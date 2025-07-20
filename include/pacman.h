#ifndef PACMAN_H
#define PACMAN_H

typedef struct pacman
{
    int x;
    int y;
    int direction;
    int lives;
} Pacman;

// create pacman at a position
Pacman pacman_init(int x, int y);

// Move pacman
void pacmanMove(Pacman *p, int dx, int dy);
// Draw pacman
void pacmanDraw(const Pacman *p);

#endif  // PACMAN_H