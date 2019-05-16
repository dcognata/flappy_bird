#ifndef FLAPPY_BIRD
# define FLAPPY_BIRD

# include <stdio.h>
# include <stdbool.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# define		SCREEN_WIDTH  288
# define		SCREEN_HEIGHT 512
# define		UP 0
# define		MIDUP 1
# define		MIDDOWN 2
# define		DOWN 3

typedef struct	s_game
{
   bool		started;
   float    dot_vel;
   int	 	flappyPosition;
}				t_game;

typedef struct	s_assets
{
   SDL_Surface	*icon;
   SDL_Surface	*currentBird;
   SDL_Surface	*birdUpFlap;
   SDL_Surface	*birdMidFlap;
   SDL_Surface	*birdDownFlap;
   SDL_Surface	*backgroundNight;
   SDL_Surface	*backgroundDay;
   SDL_Surface	*scrollBase;
   SDL_Surface	*overlayMenu;
   SDL_Surface	*gameover;
   SDL_Surface *pipe;
   SDL_Rect		birdPosition;
   SDL_Rect    pipeUpPos;
   SDL_Rect    pipeDownPos;
   SDL_Rect		overlayPosition;
   SDL_Rect		gameoverPosition;
   SDL_Rect		scrollBasePositionSrc;
   SDL_Rect		scrollBasePositionDest;
}				t_assets;

void        	_wait(int time_to_sleep);

void            init_assets(t_assets *assets);
void            init_game(t_game *game, t_assets *assets);

bool            in_game(t_game *game, t_assets *assets, SDL_Window *window, SDL_Surface *screen);

void            in_menu(t_game *game, t_assets *assets, SDL_Window *window, SDL_Surface *screen);

#endif