#include "../include/audio.h"
#include "../include/logger.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>

typedef struct audio {
    char name[64];
    Mix_Chunk *chunk;
} Sound;

static Sound sounds[64];
static int soundCount = 0;

bool AudioInit(void) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        LOG_ERROR("Failed to initialize SDL audio: %s", SDL_GetError());
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        LOG_ERROR("Failed to open SDL_mixer audio: %s", Mix_GetError());
        return false;
    }

    LOG_INFO("Audio system initialized successfully");
    return true;
}

bool AudioLoadSound(const char *name, const char *path) {
    if (soundCount >= 64) {
        LOG_ERROR("Sound limit reached — cannot load '%s'", name);
        return false;
    }

    Mix_Chunk *chunk = Mix_LoadWAV(path);
    if (!chunk) {
        LOG_ERROR("Failed to load sound '%s' from '%s': %s", name, path, Mix_GetError());
        return false;
    }

    strncpy(sounds[soundCount].name, name, sizeof(sounds[soundCount].name) - 1);
    sounds[soundCount].chunk = chunk;
    soundCount++;

    LOG_INFO("Loaded sound '%s' from '%s'", name, path);
    return true;
}

bool AudioPlaySound(const char *name) {
    for (int i = 0; i < soundCount; i++) {
        if (strcmp(sounds[i].name, name) == 0) {
            if (Mix_PlayChannel(-1, sounds[i].chunk, 0) == -1) {
                LOG_ERROR("Failed to play sound '%s': %s", name, Mix_GetError());
                return false;
            }
            LOG_INFO("Playing sound '%s'", name);
            return true;
        }
    }
    LOG_WARN("Sound '%s' not found", name);
    return false;
}

void AudioCleanUp(void) {
    for (int i = 0; i < soundCount; i++) {
        if (sounds[i].chunk) {
            Mix_FreeChunk(sounds[i].chunk);
            sounds[i].chunk = NULL;
        }
    }
    soundCount = 0;

    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);

    LOG_INFO("Audio system cleaned up");
}
