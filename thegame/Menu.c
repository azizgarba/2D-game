#include "Menu.h"
#include "globale.h"

Menu *initMenu()
{
    Menu *m;
    m = malloc(sizeof (Menu));
    m->bg = IMG_Load("bg.jpg");


    //
    m->butt_play = IMG_Load("ng_normal.png");
    m->butt_options = IMG_Load("op_normal.png");
    m->butt_quit = IMG_Load("q_normal.png");
    m->butt_load = IMG_Load("lg_normal.png");
    m->butt_cr = IMG_Load("credit_normal.png");
    m->logo = IMG_Load("logo.png");
    //
    m->ng_press = IMG_Load("ng_selected.png");
    m->lg_press = IMG_Load("lg_selected.png");
    m->op_press = IMG_Load("op_selected.png");
    m->cr_press = IMG_Load("credit_selected.png");
    m->q_press = IMG_Load("q_selected.png");
    //




    ////////////////////////////////////////////
    ////////////////////////////////////////////
    m->x_ng.w = m->ng_press->w;
    m->x_ng.h = m->ng_press->h;
    m->x_ng.x = screen->w/ 1.25 - m->x_ng.w / 2;
    m->x_ng.y = (screen->h*50/100) - m->x_ng.h/2;
    ////////////////////////////////////////////
    m->x_lg.w = m->lg_press->w;
    m->x_lg.h = m->lg_press->h;
    m->x_lg.x = screen->w/1.25 - m->x_lg.w / 2;
    m->x_lg.y = (screen->h*60/100) - m->x_lg.h/2;
    ////////////////////////////////////////////
    m->x_op.w = m->op_press->w;
    m->x_op.h = m->op_press->h;
    m->x_op.x = screen->w/1.25 - m->x_op.w / 2;
    m->x_op.y = (screen->h*70/100) - m->x_op.h / 2;
    ////////////////////////////////////////////
    m->x_crpress.w = m->cr_press->w;
    m->x_crpress.h = m->cr_press->h;
    m->x_crpress.x = screen->w/1.25 - m->x_crpress.w / 2;
    m->x_crpress.y = (screen->h*80/100) - m->x_crpress.h / 2;
    ////////////////////////////////////////////
    m->x_q.w = m->q_press->w;
    m->x_q.h = m->q_press->h;
    m->x_q.x = screen->w/1.25 - m->x_q.w / 2;
    m->x_q.y = (screen->h*90/100) - m->x_q.h/2;
    ////////////////////////////////////////////
    ////////////////////////////////////////////





    ////////////////////////////////////////////
    ////////////////////////////////////////////
    m->x_play.w = m->butt_play->w;
    m->x_play.h = m->butt_play->h;
    m->x_play.x = screen->w/ 1.25- m->x_play.w / 2;
    m->x_play.y = (screen->h*50/100) - m->x_play.h/2;
    ////////////////////////////////////////////
    m->x_load.w = m->butt_load->w;
    m->x_load.h = m->butt_load->h;
    m->x_load.x = screen->w/1.25 - m->x_load.w / 2;
    m->x_load.y = (screen->h*60/100) - m->x_load.h/2;
    ////////////////////////////////////////////
    m->x_options.w = m->butt_options->w;
    m->x_options.h = m->butt_options->h;
    m->x_options.x = screen->w/1.25 - m->x_options.w / 2;
    m->x_options.y = (screen->h*70/100) - m->x_options.h / 2;
    ////////////////////////////////////////////
    m->x_cr.w = m->butt_cr->w;
    m->x_cr.h = m->butt_cr->h;
    m->x_cr.x = screen->w/1.25 - m->x_cr.w / 2;
    m->x_cr.y = (screen->h*80/100) - m->x_cr.h / 2;
    ////////////////////////////////////////////
    m->x_quit.w = m->butt_quit->w;
    m->x_quit.h = m->butt_quit->h;
    m->x_quit.x = screen->w/1.25 - m->x_quit.w / 2;
    m->x_quit.y = (screen->h*90/100) - m->x_quit.h/2;
    ////////////////////////////////////////////
    ////////////////////////////////////////////



    ////////////////////////////////////////////
    ////////////////////////////////////////////
    m->x_logo.w = m->logo->w;
    m->x_logo.h = m->logo->h;
    m->x_logo.x = screen->w/1.25 - m->x_logo.w / 2;
    m->x_logo.y = (screen->h*35/100) - m->x_logo.h/2;
    ////////////////////////////////////////////
    ////////////////////////////////////////////



    return m;
}


void drawMenu(Menu *m)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_BlitSurface(m->bg, 0, screen,0);
    SDL_BlitSurface(m->butt_load, 0, screen, &m->x_load);
    SDL_BlitSurface(m->butt_cr, 0, screen, &m->x_cr);
    SDL_BlitSurface(m->logo, 0, screen, &m->x_logo);
    SDL_BlitSurface(m->butt_play, 0, screen, &m->x_play);
    SDL_BlitSurface(m->butt_options, 0, screen, &m->x_options);
    SDL_BlitSurface(m->butt_quit, 0, screen, &m->x_quit);
    //
}
