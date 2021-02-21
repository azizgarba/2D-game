#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    SDL_Surface *bg, *butt_play, *butt_options, *butt_quit, *butt_load, *butt_cr;
    SDL_Rect x_options, x_quit, x_load, x_cr, x_logo;
    //
} Menu;

Menu *initMenu();

void drawMenu(Menu *m);
#endif // MENU_H_INCLUDED
