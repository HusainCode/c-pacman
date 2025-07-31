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

typedef struct 
{
    int x;
    int y;
    int pacmanId;

}Pacman;

int isWall(int x, int y);

int initGameStats();

 
 int gameScore();
 void pauseGame();

 


 

#endif // GAME_H
