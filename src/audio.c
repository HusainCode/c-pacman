#include "../include/audio.h"
#include "../include/logger.h"
#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>


typedef struct audio
{
    char name[64]; 
    Mix_Chunk *chunk;

} Sound;

static Sound sounds[64];
static int soundCount = 0;

bool AudioInit(void){
     if (SDL_Init(SDL_INIT_AUDIO) < 0){
        LOG_ERROR("Failed to initialize SDL audio: %s", SDL_GetError());
        return false;
     }
     else{
        return true; // STOPPED HERE
     }




bool AudioLoadSound(const char *name, const char *path);{
    
}