#include "menu.h"
#include "globale.h"
//#include "initM.h"
#include "events.h"



int main ( int argc, char** argv )
{
    //int width = 800, height = 600; not really needed actually

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    if ( SDL_Init( SDL_INIT_AUDIO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    if(TTF_Init() == -1)
{
    printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    return 1;
}

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    screen = SDL_SetVideoMode(800, 600, 0,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if ( !screen )
    {
        printf("Unable to set 800x600 video: %s\n", SDL_GetError());
        return 1;
    }

    //--------initMe *Me = initM();
    //--------drawinitM(Me);

     Menu *m = initMenu();
    mainprogEvents(m);
    // program main loop
    // end main loop
    // free the RAM
    SDL_FreeSurface(screen);
    printf("Exited cleanly\n");
    return 0;
}
