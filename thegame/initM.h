#ifndef INITM_H_INCLUDED
#define INITM_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>

typedef struct
{
    SDL_Surface *caption;
    SDL_Rect posW;
} initMe;

initMe *initM();

void drawinitM(initMe *Me);

#endif // INITM_H_INCLUDED
