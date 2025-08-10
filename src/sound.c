#include "../include/sound.h"
#include <stdio.h>
#include <stdbool.h>    
#include "raylib.h"


static bool sound_enabled = false;

void sound_init(void) {
    // Simulate initialization
    sound_enabled = true;
    printf("[Sound] Initialized.\n");
}

bool sound_is_enabled(void) {
    return sound_enabled;
}l

void sound_enable(void) {
    sound_enabled = true;
    printf("[Sound] Sound enabled.\n");
}

void sound_disable(void) {
    sound_enabled = false;
    printf("[Sound] Sound disabled.\n");
}

void sound_play(const char *sound_name) {
    if (!sound_enabled) {
        printf("[Sound] Cannot play '%s' — sound is disabled.\n", sound_name);
        return;
    }
    printf("[Sound] Playing sound: %s\n", sound_name);
    // TODO: Add actual sound playing code here
}

void sound_stop(const char *sound_name) {
    printf("[Sound] Stopped sound: %s\n", sound_name);
    // TODO: Add actual sound stop code here
}
