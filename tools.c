#include "include/flappy_bird.h"

void            _wait(int time_to_sleep)
{
    for (int i = 0; i < time_to_sleep; i++) {
        SDL_PumpEvents();
        SDL_Delay(1);
    }
}