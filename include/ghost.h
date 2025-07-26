// =============================
//  Ghost Core Features
// =============================
// • Position — x, y grid coordinates
// • Direction — current movement (dx, dy)
// • Scared Mode — vulnerable after Pac-Man eats a power pellet
// • Respawn — returns to home after being eaten
// • Color — visual identity for each ghost
//
// | Ghost  | Nickname | Target Behavior                          |
// |--------|----------|------------------------------------------|
// | Red    | Blinky   | Directly chases Pac-Man                  |
// | Pink   | Pinky    | Aims 4 tiles ahead of Pac-Man            |
// | Blue   | Inky     | Uses both Blinky and Pac-Man's positions |
// | Orange | Clyde    | Chases when far, scatters when near      |
// =============================


#pragma once

#include <stdbool.h> // gives me boolean values 
#include <SDL2/SDL.h>


typedef enum {
    BLINKY, // 0 
    PINKY, // 1 
    INKY, // 2
    CLYDE // 3

} GhostType;

typedef struct ghost
{
    int x, y; // postion
    int dx,dy; // direction
    bool isScared; // Vulnerability state
    bool respawn; // Needs to respawn
    SDL_Color colors[5]; // red, pink, yellow, green
    SDL_Color color; // current active color
    GhostType type; // Ghost behavior type

} Ghost;

// Initializes a ghost at position (x, y)
Ghost ghostInit(int x, int y);

// Moves a ghost by dx, dy
// dx: change in x (left/right)
// dy: change in y (up/down)
void moveGhost(Ghost *ghost, int dx, int dy);

// Renders the ghost
void drawGhost(const Ghost *ghost); // read only

void makeGhostVulnerable(Ghost *ghost, bool scared );

// Updates the ghost's targeting behavior
void updateGhostTarget(
    Ghost *ghost,
    int pacmanX, int pacmanY,
    int pacmanDX, int pacmanDY,
    int blinkyX, int blinkyY
);