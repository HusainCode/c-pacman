#ifndef GAME_H
#define GAME_H

#define MAP_WIDTH 28
#define MAP_HEIGHT 31

extern int gameMap[MAP_HEIGHT][MAP_WIDTH];

// Ghost entity structure
typedef struct {
    int x;
    int y;
    int id; 
} Ghost;

int isWall(int x, int y);
void ghostMove(Ghost *g, int dx, int dy);

#endif // GAME_H
