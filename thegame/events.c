
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include "events.h"
#include "Menu.h"
#include "options.h"

void mainprogEvents(Menu *m)
{
    options *Op = initOptions();
    drawMenu(m);
    int done = 0;
    while (!done)
    {

        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
            // exit if the window is closed
            case SDL_QUIT:
                done = 1;
                break;
            // check for keypresses
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done = 1;
                }

                if (event.key.keysym.sym == SDLK_n)
                {
                    SDL_BlitSurface(m->ng_press, 0, screen, &m->x_ng);
                }
                if (event.key.keysym.sym == SDLK_l)
                {
                    SDL_BlitSurface(m->lg_press, 0, screen, &m->x_lg);
                }
                if (event.key.keysym.sym == SDLK_o)
                {

                }
                if (event.key.keysym.sym == SDLK_c)
                {

                }
                if (event.key.keysym.sym == SDLK_a)
                {

                }
            }
            case SDL_KEYUP:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done = 1;
                }

                if (event.key.keysym.sym == SDLK_n)
                {
                    SDL_BlitSurface(m->butt_play, 0, screen, &m->x_play);
                    //game();
                }
                if (event.key.keysym.sym == SDLK_l)
                {
                    SDL_BlitSurface(m->butt_load, 0, screen, &m->x_load);
                    //loadgame();
                }
                if (event.key.keysym.sym == SDLK_o)
                {
                    //optionsMenuEvents();

                    Drawoptions(Op);
                }
                if (event.key.keysym.sym == SDLK_c)
                {
                    //credit();
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    done = 1;
                }
            }
            } // end switch
        } // end events
        // finally, update the screen :)
        SDL_Flip(screen);
    }
}
