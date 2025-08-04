#ifndef GAME_H
#define GAME_H

#define MAP_WIDTH 28
#define MAP_HEIGHT 31

// Game map definition (1 = wall, 0 = path, etc.)
extern int gameMap[MAP_HEIGHT][MAP_WIDTH];

// Ghost entity structure
typedef struct {
    int x;
    int y;
    int id;
} Ghost;

// Pacman entity structure
typedef struct {
    int x;
    int y;
    int id;
} Pacman;

// Game logic functions

void gameIntro();
int isWall(int x, int y);
int initGameState(void);
int getGameScore(void);
void pauseGame(void);
void drawMap(SDL_Renderer* renderer);

#endif // GAME_H
