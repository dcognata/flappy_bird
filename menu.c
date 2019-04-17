#include "include/flappy_bird.h"

void            in_menu(t_game *game, t_assets *assets, SDL_Window *window, SDL_Surface *screen)
{
    init_game(game, assets);
    SDL_BlitSurface(assets->backgroundNight, NULL, screen, NULL); // blit it to the screen
    SDL_BlitSurface(assets->overlayMenu, NULL, screen, &assets->overlayPosition); // blit it to the screen
    SDL_UpdateWindowSurface(window);
}