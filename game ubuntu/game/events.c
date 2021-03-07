
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include "events.h"
#include "menu.h"
#include "options.h"
#include "fs.h"

void mainprogEvents(Menu *m)
{

    int Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    //loading variables for texte
     TTF_Font *police =NULL;
   police=TTF_OpenFont("Norsebold.ttf",25);
   TTF_SetFontStyle(police,TTF_STYLE_BOLD);
   SDL_Color couleurblanche={255,255,255};
   texte =TTF_RenderText_Blended(police,"Odin's Sons Production",couleurblanche);
   texte->w=208;
   texte->h=50;
   SDL_Rect positiontxt;
   positiontxt.x=0;
   positiontxt.y=575;
    //Loading variables to play as music and chunks
    Mix_Music *bg_music;
    Mix_Chunk *select1, *select2, *select3, *select4, *enter;
    select1 = Mix_LoadWAV("S1.wav");
    select2 = Mix_LoadWAV("S2.wav");
    select3 = Mix_LoadWAV("S3.wav");
    select4 = Mix_LoadWAV("S4.wav");
    enter = Mix_LoadWAV("E1.wav");
    bg_music = Mix_LoadMUS("MM2.mp3");
    enter = Mix_LoadMUS("E1.mp3");
    //Loading music variables is completed.
    //Init volume
     int v = 50;
    Mix_VolumeMusic(v);
    Mix_PlayMusic(bg_music, -1);

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
            // check for mouse clicks
            case SDL_MOUSEBUTTONDOWN:
            {
                if ((event.button.x > m->x_invis_butt3.x) && (event.button.x < m->x_invis_butt3.x + 163) && (event.button.y > m->x_invis_butt3.y) && (event.button.y < m->x_invis_butt3.y + 44))
                {
                    //SDL_BlitSurface(m->butt_options, 0, screen, 0);
                    optionsMenuEvents(Op);
                    Mix_PlayChannel(-1, enter, 1);
                      SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                }
                if ((event.motion.x > m->x_invis_butt5.x) && (event.motion.x < m->x_invis_butt5.x + 92) && (event.motion.y > m->x_invis_butt5.y) && (event.motion.y < m->x_invis_butt5.y + 44))
                {
                    done = 1;
                }
                break;

            }
            // check for mouse motion
            case SDL_MOUSEMOTION:
            {
                if ((event.motion.x > m->x_invis_butt1.x) && (event.motion.x < m->x_invis_butt1.x + 194) && (event.motion.y > m->x_invis_butt1.y) && (event.motion.y < m->x_invis_butt1.y + 44))
                {
                    SDL_BlitSurface(m->butt_play, 0, screen, 0);
                    //Mix_PlayMusic(select1, 1);
                    Mix_PlayChannel(1, select1, 1);
                      SDL_BlitSurface(texte,NULL,screen,&positiontxt);


                    break;
                }
                else if ((event.motion.x > m->x_invis_butt2.x) && (event.motion.x < m->x_invis_butt2.x + 194) && (event.motion.y > m->x_invis_butt2.y) && (event.motion.y < m->x_invis_butt2.y + 44))
                {
                    SDL_BlitSurface(m->butt_load, 0, screen, 0);
                    Mix_PlayChannel(1, select2, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
                else if ((event.motion.x > m->x_invis_butt3.x) && (event.motion.x < m->x_invis_butt3.x + 163) && (event.motion.y > m->x_invis_butt3.y) && (event.motion.y < m->x_invis_butt3.y + 44))
                {
                    SDL_BlitSurface(m->butt_options, 0, screen, 0);
                    Mix_PlayChannel(1, select3, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
                else if ((event.motion.x > m->x_invis_butt4.x) && (event.motion.x < m->x_invis_butt4.x + 150) && (event.motion.y > m->x_invis_butt4.y) && (event.motion.y < m->x_invis_butt4.y + 44))
                {
                    SDL_BlitSurface(m->butt_cr, 0, screen, 0);
                    Mix_PlayChannel(1, select4, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
                else if ((event.motion.x > m->x_invis_butt5.x) && (event.motion.x < m->x_invis_butt5.x + 92) && (event.motion.y > m->x_invis_butt5.y) && (event.motion.y < m->x_invis_butt5.y + 44))
                {
                    SDL_BlitSurface(m->butt_quit, 0, screen, 0);
                    Mix_PlayChannel(1, select1, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
                else
                {
                    SDL_BlitSurface(m->bg, 0, screen,0);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
            }

            // check for keypresses
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done = 1;
                }

                if (event.key.keysym.sym == SDLK_n)
                {
                    SDL_BlitSurface(m->butt_play, 0, screen, 0);
                    Mix_PlayChannel(1, enter, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);


                    break;

                }
                if (event.key.keysym.sym == SDLK_l)
                {
                    SDL_BlitSurface(m->butt_load, 0, screen, 0);
                    Mix_PlayChannel(1, enter, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
                if (event.key.keysym.sym == SDLK_o)
                {
                    SDL_BlitSurface(m->butt_options, 0, screen, 0);
                    Mix_PlayChannel(1, enter, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
                if (event.key.keysym.sym == SDLK_c)
                {
                    SDL_BlitSurface(m->butt_cr, 0, screen, 0);
                    Mix_PlayChannel(1, enter, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    break;
                }
                if (event.key.keysym.sym == SDLK_e)
                {
                    SDL_BlitSurface(m->butt_quit, 0, screen, 0);
                    Mix_PlayChannel(1, enter, 1);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    done = 1;
                    break;
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
                    SDL_BlitSurface(m->butt_play, 0, screen, 0);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                    //game();
                }
                if (event.key.keysym.sym == SDLK_l)
                {
                    //SDL_BlitSurface(m->butt_load, 0, screen, 0);
                    //loadgame();
                }
                if (event.key.keysym.sym == SDLK_o)
                {
                    optionsMenuEvents(Op);
                    SDL_BlitSurface(texte,NULL,screen,&positiontxt);

                }
                if (event.key.keysym.sym == SDLK_c)
                {
                    //credit();
                }
                if (event.key.keysym.sym == SDLK_e)
                {
                    done = 1;
                }

                if (event.key.keysym.sym == SDLK_MINUS)
                {
                    v = v - 10;
                }
                if (event.key.keysym.sym == SDLK_PLUS)
                {
                    v = v + 10;
                }
            }

            } // end switch
        } // end events
        // finally, update the screen :)
        SDL_Flip(screen);
    }
//free the RAM
SDL_FreeSurface(m->butt_play);
SDL_FreeSurface(m->butt_load);
SDL_FreeSurface(m->butt_cr);
SDL_FreeSurface(m->butt_options);
SDL_FreeSurface(m->butt_quit);
SDL_FreeSurface(texte);
TTF_CloseFont(police);
TTF_Quit();
}

void optionsMenuEvents(options *Op)
{
    int Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    //Loading variables to play as music and chunks
    Mix_Music *bg_music;
    Mix_Chunk *select1, *select2, *select3, *select4, *enter;
    select1 = Mix_LoadWAV("S1.wav");
    select2 = Mix_LoadWAV("S2.wav");
    select3 = Mix_LoadWAV("S3.wav");
    select4 = Mix_LoadWAV("S4.wav");
    enter = Mix_LoadWAV("E1.wav");
    bg_music = Mix_LoadMUS("MM1.mp3");
    enter = Mix_LoadMUS("E1.mp3");
    //Loading music variables is completed.
     int v = 50;
    Mix_VolumeMusic(v);
    //Mix_PlayMusic(bg_music, -1);
    Menu *m;
    Drawoptions(Op);
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
            //check for mouse clicks
            case SDL_MOUSEBUTTONUP:
            {
                if ((event.motion.x > Op->x_invisf.x) && (event.motion.x < Op->x_invisf.x + 175) && (event.motion.y > Op->x_invisf.y) && (event.motion.y < Op->x_invisf.y + 30))
                {
                    Mix_PlayChannel(1, enter, 1);
                    switchFullScreen();
                    //Menu *m = initMenu();
                    //mainprogEvents(m);
                    optionsMenuEvents(Op);

                    break;
                }
                else if ((event.motion.x > Op->x_invisw.x) && (event.motion.x < Op->x_invisw.x + 175) && (event.motion.y > Op->x_invisw.y) && (event.motion.y < Op->x_invisw.y + 30))
                {
                                        Mix_PlayChannel(1, enter, 1);
                    screen = SDL_SetVideoMode(800, 600, 0,SDL_HWSURFACE|SDL_DOUBLEBUF);

                    //Menu *m = initMenu();
                    //mainprogEvents(m);
                    optionsMenuEvents(Op);
                    //Mix_PlayMusic(select1, 1);
                    break;
                }
                else if ((event.motion.x > Op->x_invism.x) && (event.motion.x < Op->x_invism.x + 50) && (event.motion.y > Op->x_invism.y) && (event.motion.y < Op->x_invism.y + 40))
                {
                    //Mix_VolumeMusic(v) = Mix_VolumeMusic(v - 10);
                    break;
                break;

            }
            //check for mouse motion
            case SDL_MOUSEMOTION:
            {
                if ((event.motion.x > Op->x_invisf.x) && (event.motion.x < Op->x_invisf.x + 175) && (event.motion.y > Op->x_invisf.y) && (event.motion.y < Op->x_invisf.y + 30))
                {
                    SDL_BlitSurface(Op->fullscreen, 0, screen, 0);
                    Mix_PlayChannel(1, select2, 1);
                    break;
                }
                else if ((event.motion.x > Op->x_invisw.x) && (event.motion.x < Op->x_invisw.x + 175) && (event.motion.y > Op->x_invisw.y) && (event.motion.y < Op->x_invisw.y + 30))
                {
                    SDL_BlitSurface(Op->windowed, 0, screen, 0);
                    Mix_PlayChannel(1, select1, 1);
                    break;
                }
                else
                {
                    SDL_BlitSurface(Op->window, 0, screen,0);
                    break;
                }
            }
            /*
                }*/
            // check for keypresses
            case SDL_KEYUP:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done = 1;
                }

                if (event.key.keysym.sym == SDLK_f)
                {
                    switchFullScreen();
                    //Menu *m = initMenu();
                    //mainprogEvents(m);
                    optionsMenuEvents(Op);
                    //screen = SDL_SetVideoMode(0, 0, 0,SDL_FULLSCREEN); //More complicated than I thought!!!
                }
                if (event.key.keysym.sym == SDLK_w)
                {
                    screen = SDL_SetVideoMode(800, 600, 0,SDL_HWSURFACE|SDL_DOUBLEBUF);
                    //Menu *m = initMenu();
                    //mainprogEvents(m);
                    optionsMenuEvents(Op);
                }
                if (event.key.keysym.sym == SDLK_v)
                {
                    //Will work on it.. eventually.
                }
                if (event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    Menu *m = initMenu();
                    mainprogEvents(m); //<----------------
                }

            }
            }// end switch
        } // end events
        // finally, update the screen :)
        SDL_Flip(screen);
    }

}
SDL_FreeSurface(m->invis_butt1);
SDL_FreeSurface(m->invis_butt2);
SDL_FreeSurface(m->invis_butt3);
SDL_FreeSurface(m->invis_butt4);
SDL_FreeSurface(m->invis_butt5);
Mix_FreeChunk(select1);
Mix_FreeChunk(select2);
Mix_FreeChunk(select3);
Mix_FreeChunk(select4);
Mix_FreeChunk(enter);
Mix_FreeMusic(bg_music);
Mix_CloseAudio();
}
