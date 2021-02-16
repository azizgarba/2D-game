#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    SDL_Surface *bg, *butt_play, *butt_options, *butt_quit, *butt_load, *butt_cr, *logo;
    SDL_Rect x_play, x_options, x_quit, x_load, x_cr, x_logo;
    //
    SDL_Surface *ng_press, *op_press, *q_press, *lg_press, *cr_press;
    SDL_Rect x_ng, x_op, x_q, x_lg, x_crpress;
} Menu;

Menu *initMenu();

void drawMenu(Menu *m);
#endif // MENU_H_INCLUDED
