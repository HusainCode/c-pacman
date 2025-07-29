#pragma once

#define MAP_WIDTH  28
#define MAP_HEIGHT 31


#include <SDL2/SDL.h>

void guiInit();
void guiQuit();

//Present the current frame (flip the buffer)
void guiPresent();


int isWall(int x, int y) {};