#include "include/flappy_bird.h"

static int     changeFlappyPosition(int i, t_game *game, t_assets *assets)
{
    if (i >= 10) {
        if (game->flappyPosition == MIDDOWN) {
            game->flappyPosition = DOWN;
            assets->currentBird = assets->birdDownFlap;
        } else if (game->flappyPosition == DOWN) {
            game->flappyPosition = MIDUP;
            assets->currentBird = assets->birdMidFlap;
        } else if (game->flappyPosition == MIDUP) {
            game->flappyPosition = UP;
            assets->currentBird = assets->birdUpFlap;
        } else if (game->flappyPosition == UP) {
            game->flappyPosition = MIDDOWN;
            assets->currentBird = assets->birdMidFlap;
        }
        return (0);
    }
    return (i + 1);
}

static bool     colision(t_game *game, t_assets *assets)
{
    if (assets->birdPosition.y == assets->scrollBasePositionDest.y - 20)
        return (true);
    return (false);
}

static void     base_move(t_game *game, t_assets *assets, bool inJump)
{
    assets->scrollBasePositionSrc.x += game->dot_vel;
    if (assets->scrollBasePositionSrc.x >= 288)
        assets->scrollBasePositionSrc.x = 0;
    if (!inJump)
        assets->birdPosition.y += 2;
}

static void     flappy_jump(t_game *game, t_assets *assets)
{
    assets->birdPosition.y -= 2;
}

bool            in_game(t_game *game, t_assets *assets, SDL_Window *window, SDL_Surface *screen)
{
    bool        run = true;
    Uint32      lastrender = 0;
    SDL_Event   e;

    int i = 0;
    bool inJump = false;
    int jump = 0;
    bool gameover = false;
    while (run)
    {
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                run = false;
            }
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                jump = 0;
                inJump = true;
            }
        }

        // carte horizontale + joueur qui descend seul
        base_move(game, assets, inJump);
        // joueur qui saute (annule la descente dans base_move())
        if (inJump) {
            jump += 1;
            if (jump >= 30) {
                jump = 0;
                inJump = false;
            } else {
                flappy_jump(game, assets);
            }
        }

        SDL_BlitSurface(assets->backgroundDay, NULL, screen, NULL);
        SDL_BlitSurface(assets->scrollBase, &assets->scrollBasePositionSrc, screen, &assets->scrollBasePositionDest);
        if (!gameover)
        {
            SDL_BlitSurface(assets->currentBird, NULL, screen, &assets->birdPosition);
            i = changeFlappyPosition(i, game, assets);
            gameover = colision(game, assets);
        }
        else
        {
            SDL_BlitSurface(assets->gameover, NULL, screen, &assets->gameoverPosition);
        }
        SDL_UpdateWindowSurface(window);

        if (SDL_GetTicks() < (lastrender + 1000 / 60)) {
            _wait((lastrender + 1000 / 60) - SDL_GetTicks());
        }
        lastrender = SDL_GetTicks();
    }

    return (false);
}