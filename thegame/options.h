#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>


typedef struct {
SDL_Surface *window, *windowed, *fullscreen, *volume;
SDL_Rect x_window, x_windowed, x_fullscreen, x_volume;
} options;



options *initOptions();

void Drawoptions(options *Op);

#endif // OPTIONS_H_INCLUDED
