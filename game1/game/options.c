#include "options.h"
#include "globale.h"
#include "head.h"

options *initOptions()
{
    options *Op;
    Op = malloc (sizeof(options));


    Op->window = IMG_Load("option_menu.png");
    //
    //
    Op->windowed = IMG_Load("windowed_selected.png");
    //
    //
    Op->fullscreen = IMG_Load("fs_selected.png");
    //
    //

    //following the same method used at the main menu, invisible blocks.
    //we'll need around 4 blocks, fullscreen, windowed, + sign and - sign.
    //Fun. Alot of fun.

    //Block one, fullscreen.
    Op->invisf = IMG_Load("invf.png");
    //
    Op->x_invisf.w = Op->invisf->w;
    Op->x_invisf.h = Op->invisf->h;
    Op->x_invisf.x = screen->w/2 - Op->x_invisf.w / 2;
    Op->x_invisf.y = (screen->h*25 / 100) - Op->x_invisf.h/2;
    //


    //Block two, windowed.
    Op->invisw = IMG_Load("invw.png");
    //
    Op->x_invisw.w = Op->invisw->w;
    Op->x_invisw.h = Op->invisw->h;
    Op->x_invisw.x = screen->w/2 - Op->x_invisw.w / 2;
    Op->x_invisw.y = (screen->h*38 / 100) - Op->x_invisw.h/2;
    //

    //Block three, minus sing.
    Op->invism = IMG_Load("invm.png");
    //
    Op->x_invism.w = Op->invism->w;
    Op->x_invism.h = Op->invism->h;
    Op->x_invism.x = screen->w/2 - Op->x_invism.w / 2;
    Op->x_invism.y = screen->h/2 - Op->x_invism.h/2;
    //

    //Block four, plus sing.
    Op->invisp = IMG_Load("invp.png");
    //
    Op->x_invisp.w = Op->invisp->w;
    Op->x_invisp.h = Op->invisp->h;
    Op->x_invisp.x = screen->w/2 - Op->x_invisp.w / 2;
    Op->x_invisp.y = screen->h/2 - Op->x_invisp.h/2;
    //




}

void Drawoptions(options *Op)
{

    SDL_BlitSurface(Op->window, 0, screen,0);
}
