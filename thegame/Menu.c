#include "Menu.h"
#include "globale.h"

Menu *initMenu()
{
    //Init Menu
    Menu *m;
    m = malloc(sizeof (Menu));
    m->bg = IMG_Load("bg.png");
    //Init Audio for the Menu
    //int Mix_Init(MIX_INIT_MP3);


    //
    //
    ////////////////////////////////////////////
    ////////////////////////////////////////////
    //New game selection Menu
    m->butt_play = IMG_Load("ng_normal.png");
    ////////////////////////////////////////////
    //Load game selection Menu
    m->butt_load = IMG_Load("lg_normal.png");
    ////////////////////////////////////////////
    //Options selection Menu
    m->butt_options = IMG_Load("op_normal.png");
    ////////////////////////////////////////////
    //Credit selection menu
    m->butt_cr = IMG_Load("credit_normal.png");
    ////////////////////////////////////////////
    //quit selection menu
    m->butt_quit = IMG_Load("q_normal.png");
    ////////////////////////////////////////////
    ////////////////////////////////////////////





    return m;
}


void drawMenu(Menu *m)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_BlitSurface(m->bg, 0, screen,0);
    //SDL_BlitSurface(m->butt_load, 0, screen, &m->x_load);
    //SDL_BlitSurface(m->butt_cr, 0, screen, &m->x_cr);
    //SDL_BlitSurface(m->logo, 0, screen, &m->x_logo);
    //SDL_BlitSurface(m->butt_play, 0, screen, &m->x_play);
    //SDL_BlitSurface(m->butt_options, 0, screen, &m->x_options);
    //SDL_BlitSurface(m->butt_quit, 0, screen, &m->x_quit);
    //
}
