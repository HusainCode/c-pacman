 #pragma once


#include <stdbool.h>
#include <SDL2/SDL_mixer.h>

/// Initializes the audio system (must be called before using any audio functions)
bool AudioInit(void);

// Loads a short sound effect into memory
bool AudioLoadSound(const char *name, const char *path);

// Plays a previously loaded sound effect by name
void AudioPlaySound(const char *name);

// Loads a streaming music track (good for long songs)
bool AudioLoadMusic(const char *name, const char *path);

// Plays a loaded music track (loops = -1 for infinite loop)
void AudioPlayMusic(const char *name, int loops);

// Stops any playing music
void AudioStopMusic(void);

// Frees all loaded sounds/music and shuts down the audio system
void AudioCleanup(void);

 
