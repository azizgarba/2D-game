#include "fs.h"
#include "globale.h"
SDL_Surface* switchFullScreen()
{/**fullscreen ou pas...***VALIDE***/

        /*****DECLARATIONS*****/

    SDL_Surface *screen =SDL_GetVideoSurface();/*reprise de la surface d'affichage*/
    Uint32 flags        =(screen->flags^SDL_FULLSCREEN);/*insertion du bit fullscreen*/

        /*****EXECUTION*****/

    screen =SDL_SetVideoMode(0, 0, 0, flags);/*création de la surface*/

    if (screen==NULL)
    {/*gestion d'erreur*/
        fprintf(stderr, "Err / switchFullScreen : changement de format impossible :%s\n",   SDL_GetError());
        screen=SDL_SetVideoMode(0, 0, 0, flags^SDL_FULLSCREEN);/*retour au mode précédent*/
    }

        /*****POST*****/

    return(screen);
}
