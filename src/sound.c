#include "../include/sound.h"
#include <stdio.h>

static bool sound_enabled = false;

void sound_init(void) {
    //  simulate init
    sound_enabled = true;
   
}

bool sound_is_enabled(void) {
    return sound_enabled;
}
