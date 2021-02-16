#include "initM.h"
#include "globale.h"


initMe *initM() {
    initMe *Me;

    Me = malloc(sizeof (initMe));

    Me->caption = IMG_Load("continue.png");  //<--------------- crash here

    Me->posW.w = Me->caption->w;

    Me->posW.h = Me->caption->h;

    Me->posW.x = screen->w/2 - Me->posW.w / 2;

    Me->posW.y = (screen->h*90/100) - Me->posW.h/2;

    return Me;
    }


void drawinitM(initMe *Me) {
    SDL_BlitSurface(Me->caption, 0, screen, &Me->posW);
}
