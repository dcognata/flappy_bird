#include "include/flappy_bird.h"

int 	        main(void)
{
    bool        run = true;
    bool        inGame = false;
    Uint32      lastrender = 0;
    t_assets    assets;
    t_game      game;
    SDL_Surface *screen;
    SDL_Window  *window;
    SDL_Event   e;

    if (SDL_Init(SDL_INIT_VIDEO) < 0 || (window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
    {
        printf("Failed to create window! SDL_Error: %s\n", SDL_GetError());
        return (-1);
    }
    SDL_SetWindowIcon(window, assets.icon);
    screen = SDL_GetWindowSurface(window);

    init_assets(&assets);
	while (run)
    {
		while(SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                run = false;
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
                inGame = true;
        }

        if (inGame == false)
            in_menu(&game, &assets, window, screen);
        else
            inGame = in_game(&game, &assets, window, screen);;

        if (SDL_GetTicks() < (lastrender + 1000 / 60))
            _wait((lastrender + 1000 / 60) - SDL_GetTicks());
        lastrender = SDL_GetTicks();
	}

    SDL_FreeSurface(screen);
    SDL_FreeSurface(assets.pipe);
    SDL_FreeSurface(assets.icon);
    SDL_FreeSurface(assets.backgroundDay);
    SDL_FreeSurface(assets.backgroundNight);
    SDL_FreeSurface(assets.overlayMenu);
    SDL_FreeSurface(assets.scrollBase);
    SDL_FreeSurface(assets.birdUpFlap);
    SDL_FreeSurface(assets.birdMidFlap);
    SDL_FreeSurface(assets.birdDownFlap);
    SDL_FreeSurface(assets.gameover);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}