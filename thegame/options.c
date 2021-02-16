#include "options.h"
#include "globale.h"


options *initOptions() {
    options *Op;
    Op = malloc (sizeof(options));


    Op->window = IMG_Load("option_menu.png");
    //
    Op->x_window.w = Op->window->w;
    Op->x_window.h = Op->window->h;
    Op->x_window.x = screen->w/2 - Op->x_window.w / 2;
    Op->x_window.y = screen->h/2 - Op->x_window.h/2;
    //


    Op->windowed = IMG_Load("windowed.png");
    //
    Op->x_windowed.w = Op->windowed->w;
    Op->x_windowed.h = Op->windowed->h;
    Op->x_windowed.x = screen->w/2 - Op->x_windowed.w / 2;
    Op->x_windowed.y = screen->h/3 - Op->x_windowed.h/2;
    //


     Op->fullscreen = IMG_Load("full_screen.png");
    //
    Op->x_fullscreen.w = Op->fullscreen->w;
    Op->x_fullscreen.h = Op->fullscreen->h;
    Op->x_fullscreen.x = screen->w/2 - Op->x_fullscreen.w / 2;
    Op->x_fullscreen.y = screen->h/2 - Op->x_fullscreen.h/2;
    //

    Op->volume = IMG_Load("volume.png");
    //
    Op->x_volume.w = Op->volume->w;
    Op->x_volume.h = Op->volume->h;
    Op->x_volume.x = screen->w/3 - Op->x_volume.w / 2;
    Op->x_volume.y = screen->h/1.50 - Op->x_volume.h/2;
    //

}

void Drawoptions(options *Op) {

SDL_BlitSurface(Op->window, 0, screen,&Op->x_window);
//
SDL_BlitSurface(Op->windowed, 0, screen,&Op->x_windowed);
//
SDL_BlitSurface(Op->fullscreen, 0, screen,&Op->x_fullscreen);
//
SDL_BlitSurface(Op->volume, 0, screen,&Op->x_volume);
}
