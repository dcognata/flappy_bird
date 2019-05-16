#include "include/flappy_bird.h"

/**
 * CHARGER LES IMAGES ET LES SONS DANS LES STRUCTURES DEFINIE DANS LE FICHIER :
 * "assets/flappy_bird.h"
 */

void            init_assets(t_assets *assets)
{
    assets->icon = SDL_LoadBMP("./assets/sprites/flappy_bird_icon.bmp");
    assets->backgroundDay = IMG_Load("./assets/sprites/background-day.png");
    assets->backgroundNight = IMG_Load("./assets/sprites/background-night.png");
    assets->overlayMenu = IMG_Load("./assets/sprites/message.png");
    assets->scrollBase = IMG_Load("./assets/sprites/base.png");
    assets->birdUpFlap = IMG_Load("./assets/sprites/bluebird-upflap.png");
    assets->birdMidFlap = IMG_Load("./assets/sprites/bluebird-midflap.png");
    assets->birdDownFlap = IMG_Load("./assets/sprites/bluebird-downflap.png");
    assets->gameover = IMG_Load("./assets/sprites/gameover.png");
    assets->pipe = IMG_Load("./assets/sprites/pipe-green.png");
    assets->currentBird = assets->birdMidFlap;
    assets->overlayPosition.x = (assets->backgroundNight->w - assets->overlayMenu->w) / 2;
    assets->overlayPosition.y = (assets->backgroundNight->h - assets->overlayMenu->h) / 2;
    assets->overlayPosition.w = assets->backgroundNight->w;
    assets->overlayPosition.h = assets->backgroundNight->h;
    assets->gameoverPosition.x = (assets->backgroundNight->w - assets->gameover->w) / 2;
    assets->gameoverPosition.y = (assets->backgroundNight->h - assets->gameover->h) / 2;
    assets->gameoverPosition.w = assets->backgroundNight->w;
    assets->gameoverPosition.h = assets->backgroundNight->h;
    if (!assets->backgroundDay || !assets->backgroundNight || !assets->overlayMenu
        || !assets->scrollBase|| !assets->birdUpFlap || !assets->birdMidFlap
        || !assets->birdDownFlap || !assets->gameover) {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
        exit(-1);
    }
}

void            init_game(t_game *game, t_assets *assets)
{
    game->started = true;
    game->dot_vel = (float)1.0;
    game->flappyPosition = MIDDOWN;
    assets->birdPosition.x = 50;
    assets->birdPosition.y = 200;
    assets->birdPosition.w = assets->birdMidFlap->w;
    assets->birdPosition.h = assets->birdMidFlap->h;
    assets->scrollBasePositionSrc.x = 0;
    assets->scrollBasePositionSrc.y = 0;
    assets->scrollBasePositionSrc.w = assets->scrollBase->w;
    assets->scrollBasePositionSrc.h = assets->scrollBase->h;
    assets->scrollBasePositionDest.x = 0;
    assets->scrollBasePositionDest.y = 400;
    assets->scrollBasePositionDest.w = assets->scrollBase->w;
    assets->scrollBasePositionDest.h = assets->scrollBase->h;
    assets->pipeUpPosSrc.x = 0;
    assets->pipeUpPosSrc.y = 0;
    assets->pipeUpPosSrc.w = assets->pipe->w;
    assets->pipeUpPosSrc.h = assets->pipe->h;
    assets->pipeUpPosDest.x = 0;
    assets->pipeUpPosDest.y = 0;
    assets->pipeUpPosDest.w = assets->pipe->w;
    assets->pipeUpPosDest.h = assets->pipe->h;
}