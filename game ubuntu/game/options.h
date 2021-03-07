#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>


typedef struct {
SDL_Surface *window, *windowed, *fullscreen;
SDL_Rect x_window, x_windowed, x_fullscreen;
//invisible blocks
SDL_Surface *invisf, *invisw, *invism, *invisp;
SDL_Rect x_invisf, x_invisw, x_invism, x_invisp;
} options;



options *initOptions();

void Drawoptions(options *Op);

#endif // OPTIONS_H_INCLUDED
