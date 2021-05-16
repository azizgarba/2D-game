#include"head.h"
int frameNb = 10;
Menu *initMenu()
{
    //Init Menu
    Menu *m;
    m = malloc(sizeof (Menu));
    m->bg = IMG_Load("bg1.png");


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

    //since we're using plain menu images to show our actual menu,
    //we find problems in the selection when using mouse motion
    //I've thought about a quick solution, implementing invisible squares beneath the menu image,
    //these invis squares will serve as captors for the mouse motion
    //It's going to be only one image but loaded at 5 different places
    //while using the mouse motion, i'll use the invis square to change between menu options once the mouse
    //was detected on it :)
    //as I thought, I'm going to need to load 5 invis squares of different dimensions, pain in the butt.


    //first block
    m->invis_butt1 = IMG_Load("inv1.png");
    m->x_invis_butt1.w = m->invis_butt1->w;
    m->x_invis_butt1.h = m->invis_butt1->h;
    m->x_invis_butt1.x = screen->w/1.25 - m->x_invis_butt1.w/2;
    m->x_invis_butt1.y = (screen->h*40 / 100) - m->x_invis_butt1.h/2;


    //second block
    m->invis_butt2 = IMG_Load("inv2.png");
    m->x_invis_butt2.w = m->invis_butt2->w;
    m->x_invis_butt2.h = m->invis_butt2->h;
    m->x_invis_butt2.x = screen->w/1.25 - m->x_invis_butt2.w/2;
    m->x_invis_butt2.y = (screen->h*50 / 100) - m->x_invis_butt2.h/2;

    //third block
    m->invis_butt3 = IMG_Load("inv3.png");
    m->x_invis_butt3.w = m->invis_butt3->w;
    m->x_invis_butt3.h = m->invis_butt3->h;
    m->x_invis_butt3.x = screen->w/1.25 - m->x_invis_butt3.w/2;
    m->x_invis_butt3.y = (screen->h*60 / 100) - m->x_invis_butt3.h/2;

    //fourth block
    m->invis_butt4 = IMG_Load("inv4.png");
    m->x_invis_butt4.w = m->invis_butt4->w;
    m->x_invis_butt4.h = m->invis_butt4->h;
    m->x_invis_butt4.x = screen->w/1.25 - m->x_invis_butt4.w/2;
    m->x_invis_butt4.y = (screen->h*70 / 100) - m->x_invis_butt4.h/2;

    //fifth block
    m->invis_butt5 = IMG_Load("inv5.png");
    m->x_invis_butt5.w = m->invis_butt5->w;
    m->x_invis_butt5.h = m->invis_butt5->h;
    m->x_invis_butt5.x = screen->w/1.10 - m->x_invis_butt5.w/2;
    m->x_invis_butt5.y = (screen->h*80 / 100) - m->x_invis_butt5.h/2;
    return m;
}


void drawMenu(Menu *m)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(m->bg, 0, screen,0);
}

/*enigme *generer()
{
    enigme *e;
    e = malloc(sizeof (enigme));

    e->bg = IMG_Load("bg12.png");

    e->butt_play = IMG_Load("play.png");

    e->pl1 = IMG_Load("play1.png");
    e->pl2 = IMG_Load("play2.png");
    e->pl3 = IMG_Load("play3.png");

    e->trp1 = IMG_Load("trp1.png");
    e->trp2 = IMG_Load("trp2.png");
    e->trp3 = IMG_Load("trp3.png");


    e->x_trp1.w = e->trp1->w;
    e->x_trp1.h = e->trp1->h;
    e->x_trp1.x = screen->w/2 - e->x_trp1.w/2;
    e->x_trp1.y = screen->h/2.3 - e->x_trp1.h/2;

    e->x_trp2.w = e->trp2->w;
    e->x_trp2.h = e->trp2->h;
    e->x_trp2.x = screen->w/2 - e->x_trp2.w/2;
    e->x_trp2.y = screen->h/1.9 - e->x_trp2.h/2;


    e->x_trp3.w = e->trp3->w;
    e->x_trp3.h = e->trp3->h;
    e->x_trp3.x = screen->w/2 - e->x_trp3.w/2;
    e->x_trp3.y = screen->h/1.7 - e->x_trp3.h/2;


    e->bse = IMG_Load("bse.png");

    e->instruc = IMG_Load("instructions.png");


    e->x_p.w = e->butt_play->w;
    e->x_p.h = e->butt_play->h;
    e->x_p.x = screen->w/2 - e->x_p.w/2;
    e->x_p.y = screen->h/2 - e->x_p.h/2;

    e->x_bse.w = e->bse->w;
    e->x_bse.h = e->bse->h;
    e->x_bse.x = screen->w/2 - e->x_bse.w/2;
    e->x_bse.y = screen->h/2 - e->x_bse.h/2;

    ////////////////////////////////////
    e->c1 = IMG_Load("1.png");
    e->c2 = IMG_Load("2.png");
    e->c3 = IMG_Load("3.png");
    e->c4 = IMG_Load("4.png");
    e->c5 = IMG_Load("5.png");
    e->c6 = IMG_Load("6.png");
    e->c7 = IMG_Load("7.png");
    e->c8 = IMG_Load("8.png");
    e->c9 = IMG_Load("9.png");
    e->c10 = IMG_Load("10.png");

    e->x_c.w = e->c1->w;
    e->x_c.h = e->c1->h;
    e->x_c.x = screen->w/2 - e->x_c.w/2;
    e->x_c.y = screen->h/1.25 - e->x_c.h/2;

    ////////////////////////////////////
    e->p1 = IMG_Load("p1.png");
    e->p2 = IMG_Load("p2.png");
    e->p3 = IMG_Load("p3.png");
    e->p4 = IMG_Load("p4.png");
    e->p5 = IMG_Load("p5.png");
    e->p6 = IMG_Load("p6.png");
    e->p7 = IMG_Load("p7.png");
    e->p8 = IMG_Load("p8.png");
    e->p9 = IMG_Load("p9.png");


    e->x_po.w = e->p1->w;
    e->x_po.h = e->p1->h;
    e->x_po.x = screen->w/2 - e->x_po.w/2;
    e->x_po.y = screen->h/1.75 - e->x_po.h/2;

    ////////////////////////////////////

    e->yw = IMG_Load("yw.png");
    e->yl = IMG_Load("yl.png");
    return e;
}

void afficherEnigme(enigme *e)
{
    int points;
    int done = 1;

    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(e->bg, 0, screen,0);
    SDL_BlitSurface(e->butt_play, 0, screen,&e->x_p);
    SDL_Event event;
    SDL_Event event2;
    while (done)
    {

        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            done = 0;
            break;
        case SDL_MOUSEBUTTONUP:
        {
            if ((event.button.x > e->x_trp1.x) && (event.button.x < e->x_trp1.x + 200) && (event.button.y > e->x_trp1.y) && (event.button.y < e->x_trp1.y + 55))
            {

                points = algoenigme(e);
                if (points >= 10)
                {
                    SDL_BlitSurface(e->yw, 0, screen,0);

                }
                if (points <= 0)
                {
                    SDL_BlitSurface(e->yl, 0, screen,0);

                }
            }
            if ((event.button.x > e->x_trp2.x) && (event.button.x < e->x_trp2.x + 200) && (event.button.y > e->x_trp2.y) && (event.button.y < e->x_trp2.y + 38))
            {
                showinstructions(e);
            }
            if ((event.button.x > e->x_trp3.x) && (event.button.x < e->x_trp3.x + 200) && (event.button.y > e->x_trp3.y) && (event.button.y < e->x_trp3.y + 25))
            {
                done = 0;
            }
            break;

        }
        case SDL_MOUSEMOTION:
        {
            if ((event.button.x > e->x_trp1.x) && (event.button.x < e->x_trp1.x + 200) && (event.button.y > e->x_trp1.y) && (event.button.y < e->x_trp1.y + 55))
            {

                SDL_BlitSurface(e->pl1, 0, screen,&e->x_p);
                break;
            }
            else if ((event.button.x > e->x_trp2.x) && (event.button.x < e->x_trp2.x + 200) && (event.button.y > e->x_trp2.y) && (event.button.y < e->x_trp2.y + 38))
            {
                SDL_BlitSurface(e->pl2, 0, screen,&e->x_p);
            }
            else if ((event.button.x > e->x_trp3.x) && (event.button.x < e->x_trp3.x + 200) && (event.button.y > e->x_trp3.y) && (event.button.y < e->x_trp3.y + 25))
            {
                SDL_BlitSurface(e->pl3, 0, screen,&e->x_p);
            }
            else
            {
                SDL_BlitSurface(e->butt_play, 0, screen,&e->x_p);
            }
            break;
        }
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_p:
                points = algoenigme(e);
                if (points >= 10)
                {
                    SDL_BlitSurface(e->yw, 0, screen,0);

                }
                if (points <= 0)
                {
                    SDL_BlitSurface(e->yl, 0, screen,0);

                }
                break;
            case SDLK_i:
                showinstructions(e);
                break;
            case SDLK_e:
                done = 0;
                break;
            }
            break;
        }
        SDL_Flip(screen);//rafraichir l'ecran
    }

}

void showinstructions(enigme *e)
{
    int done = 1;
    SDL_Event event;
    SDL_BlitSurface(e->instruc, 0, screen,0);
    while (done)
    {

        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            done = 0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_e:
                afficherEnigme(e);
                break;
            }
            break;
        }
        SDL_Flip(screen);//rafraichir l'ecran
    }
}

int algoenigme(enigme *e)
{
    int done = 1;
    int choice,x,y,pick,points;
    points = 3;
    SDL_Event event;
    srand(time(0));
    x = (rand() % 10) + 1;
    while (done)
    {
        y = (rand() % 10) + 1;
        SDL_BlitSurface(e->bg, 0, screen,0);
        SDL_BlitSurface(e->bse, 0, screen,&e->x_bse);
        SDL_WaitEvent(&event);

        switch (x)
        {
        case 1:
            SDL_BlitSurface(e->c1, 0, screen,&e->x_c);
            break;
        case 2:
            SDL_BlitSurface(e->c2, 0, screen,&e->x_c);
            break;
        case 3:
            SDL_BlitSurface(e->c3, 0, screen,&e->x_c);
            break;
        case 4:
            SDL_BlitSurface(e->c4, 0, screen,&e->x_c);
            break;
        case 5:
            SDL_BlitSurface(e->c5, 0, screen,&e->x_c);
            break;
        case 6:
            SDL_BlitSurface(e->c6, 0, screen,&e->x_c);
            break;
        case 7:
            SDL_BlitSurface(e->c7, 0, screen,&e->x_c);
            break;
        case 8:
            SDL_BlitSurface(e->c8, 0, screen,&e->x_c);
            break;
        case 9:
            SDL_BlitSurface(e->c9, 0, screen,&e->x_c);
            break;
        case 10:
            SDL_BlitSurface(e->c10, 0, screen,&e->x_c);
            break;
        }
        switch (points)
        {
        case 1:
            SDL_BlitSurface(e->p1, 0, screen,&e->x_po);
            break;
        case 2:
            SDL_BlitSurface(e->p2, 0, screen,&e->x_po);
            break;
        case 3:
            SDL_BlitSurface(e->p3, 0, screen,&e->x_po);
            break;
        case 4:
            SDL_BlitSurface(e->p4, 0, screen,&e->x_po);
            break;
        case 5:
            SDL_BlitSurface(e->p5, 0, screen,&e->x_po);
            break;
        case 6:
            SDL_BlitSurface(e->p6, 0, screen,&e->x_po);
            break;
        case 7:
            SDL_BlitSurface(e->p7, 0, screen,&e->x_po);
            break;
        case 8:
            SDL_BlitSurface(e->p8, 0, screen,&e->x_po);
            break;
        case 9:
            SDL_BlitSurface(e->p9, 0, screen,&e->x_po);
            break;
        }

        switch(event.type)
        {
        case SDL_QUIT:
            done = 0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_b:
                if (x > y)
                {
                    points += 1;
                }
                else if (x < y || x == y)
                {
                    points -= 2;
                }
                x = y;
                break;
            case SDLK_s:
                if (x < y)
                {
                    points += 1;

                }
                else if (x > y || x == y)
                {
                    points -= 2;

                }
                x = y;
                break;
            case SDLK_e:
                if (x == y)
                {
                    points += 3;

                }
                else if (x > y || x < y)
                {
                    points -= 3;

                }
                x = y;
                break;
            }
            break;

        }
        if (points >= 10 || points <= 0)
        {
            return points;
        }

        SDL_Flip(screen);//rafraichir l'ecran
    }


}*/
void init_background(background* bg,char image[], int x, int y, int w, int h)
{
    bg->image=NULL;
    bg->image=IMG_Load(image);
    bg->camera.x=x;
    bg->camera.y=y;
    bg->camera.w=w;
    bg->camera.h=h;
}


void affiche_background(background* bg, SDL_Surface *screen, SDL_Rect bg1)
{
    SDL_BlitSurface(bg->image, &(bg->camera), screen, &bg1);
}


void scrolling (SDL_Rect* camera, int speed,int x, int l)
{
    //enigme *e = generer();
    if(l==0)
    {
        if (camera->x <= 1000)
        {
            x += speed;
            camera->x += speed;

        }
    }


    else if (l==1)
    {
        if (camera->x >= 50)
        {
            x -= speed;

            camera->x -= speed;
        }
    }
    if (camera->x == 1000)
    {
       // afficherEnigme(e);

    }
}


void ham(SDL_Surface *screen)
{
    int comp = 2;
    SDL_Color white = {0, 0, 0};
    int done=1, x =0, l = 0, speed = 10;
    int keep=1;
    SDL_Surface *top_bg,*score,*texte;
    Hero hero;
    Ennemi e;
    top_bg = IMG_Load("top_bg.jpg");
    int attack=0;
    char direction[50];
    char scoreText[100];
    Hero *test=&hero;
    TTF_Init();
    TTF_Font *police =NULL;
    police=TTF_OpenFont("Norse.ttf",50);
    TTF_SetFontStyle(police,TTF_STYLE_BOLD);
    SDL_Color couleurblanche={255,255,255};
    texte =TTF_RenderText_Blended(police,"Press e",couleurblanche);
    texte->w=160;
    texte->h=50;
    SDL_Rect positiontxt;
    positiontxt.x=320;
    positiontxt.y=100;
    enigme s;
    SDL_Surface *win , *loss ;
    win=IMG_Load("win.png");
    loss=IMG_Load("loss.png");

    /*score = TTF_RenderText_Blended(police, scoreText, white);
    sprintf(scoreText, "Score: %d", hero.score);*/
    Uint32 dt, t_prev;


    ///////////////////////////////////
    background bg;
    if (comp == 1)
    {
        init_background(&bg,"LVL1.png",0,0,800,600);
    }
    else if (comp == 2)
    {
        init_background(&bg,"LVL2.png",0,0,800,600);
    }
    else if (comp == 3)
    {
        init_background(&bg,"LVL3.png",0,0,800,600);
    }

    //init_background(&bg2,"bg.png",0,0,400,600);
    SDL_Rect posbg1;
    posbg1.x = 0;
    posbg1.y = 0;
    ////////////////////////////////////
    Input I;
    int run=0;
    int collision;
    init_hero(&hero);
    if(attack==0)
    {
        initEnnemi(&e);
    }
    init_input(&I);

    while (done)
    {
         deplacer(&e);
            d = e.enem.x-hero.heroPos.x;
            //deplacerIA(&e);
            animerEnnemi(&e);
            affiche_background(&bg, screen, posbg1);
            afficher_Hero(&hero, screen, top_bg, score);
            if(attack==0)
            {
                afficherEnnemi(e,screen);
            }
            if(hero.heroPos.x>=627)
            {
             SDL_BlitSurface(texte,NULL,screen,&positiontxt);
             //SDL_Flip(screen);
            }
            SDL_Flip(screen);
        t_prev = SDL_GetTicks();
        if (hero.currentMode == 0 || hero.currentMode == 2 || hero.currentMode == 4 || hero.currentMode == 6)
        {
            strcpy(direction, "right");
        }
        else
        {
            strcpy(direction, "left");
        }
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
            // exit if the window is closed
            case SDL_QUIT:
                done = 0;
                break;
            case SDL_KEYDOWN:
            {

                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    I.jump=1;
                    break;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    l = 0;
                    I.right=1;
                    hero.currentMode=2;
                    scrolling (&(bg.camera), speed, x, l);
                    //printf("%d\n",test->heroPos.x);
                    break;
                }
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    l = 1;
                    I.left=1;
                    hero.currentMode=3;
                    scrolling (&(bg.camera), speed, x, l);


                    break;
                }
                if(event.key.keysym.sym==SDLK_x)
                {
                    I.attack = 1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 6;
                    }
                    else
                    {
                        hero.currentMode = 7;
                    }
                    break;
                }
                // check for mouse clicks
            }
            case SDL_KEYUP:
            {


                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    I.jump=0;
                    if (I.right == 1)
                    {
                        hero.currentMode = 2;
                    }
                    else if (I.left == 1)
                    {
                        hero.currentMode = 3;
                    }
                    else
                    {
                        if (strcmp(direction, "right") == 0)
                        {
                            hero.currentMode = 0;
                        }
                        else
                        {
                            hero.currentMode = 1;
                        }
                    }



                    break;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    scrolling (&(bg.camera), speed, x, l);
                    I.right = 0;
                    hero.currentMode = 0;
                    run = 0;

                    break;
                }
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    scrolling (&(bg.camera), speed, x, l);
                    I.left = 0;
                    hero.currentMode = 1;
                    run = 0;
                    break;
                }
                if (event.key.keysym.sym == SDLK_x)
                {
                    I.attack = 0;
                    attack=1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 0;
                    }
                    else
                    {
                        hero.currentMode = 1;
                    }
                    break;
                }
            }
            dt = SDL_GetTicks() - t_prev; // end switch
            SDL_Flip(screen);
            }
            affiche_background(&bg, screen, posbg1);

            leftAndRightHeroMvtR(&hero, I, dt, comp);
            //run left and right

            //jump movement
            jumpHeroMvt(&hero, I, &run);
            //jump movement


            idleAnimation(&hero);
            if(hero.heroPos.x>=627)
            {
             SDL_BlitSurface(texte,NULL,screen,&positiontxt);
             //SDL_Flip(screen);
            }
            deplacer(&e);
            animerEnnemi(&e);
            if(attack==0)
            {
                afficherEnnemi(e,screen);
            }
            runAnimation(&hero);
            if(hero.heroPos.x>=627)
            {
             SDL_BlitSurface(texte,NULL,screen,&positiontxt);
             //SDL_Flip(screen);
            }
             deplacer(&e);
            animerEnnemi(&e);
            if(attack==0)
            {
                afficherEnnemi(e,screen);
            }
            jumpAnimation(&hero, screen, bg.image, posbg1, run);
            if(hero.heroPos.x>=627)
            {
             SDL_BlitSurface(texte,NULL,screen,&positiontxt);
             //SDL_Flip(screen);
            }
             deplacer(&e);
            animerEnnemi(&e);
            if(attack==0)
            {
                afficherEnnemi(e,screen);
            }
            deadAnimation(&hero, screen, bg.image, posbg1);
            if(hero.heroPos.x>=627)
            {
             SDL_BlitSurface(texte,NULL,screen,&positiontxt);
             //SDL_Flip(screen);
            }
             deplacer(&e);
            animerEnnemi(&e);
            if(attack==0)
            {
                afficherEnnemi(e,screen);
            }
            attackAnimation(&hero, screen, bg.image,posbg1);
            if(hero.heroPos.x>=627)
            {
             SDL_BlitSurface(texte,NULL,screen,&positiontxt);
             //SDL_Flip(screen);
            }
             deplacer(&e);
            animerEnnemi(&e);
            afficher_Hero(&hero, screen, top_bg, score);
            if(attack==0)
            {
                afficherEnnemi(e,screen);
            }
            if(hero.heroPos.x>=627)
            {
             SDL_BlitSurface(texte,NULL,screen,&positiontxt);
             //SDL_Flip(screen);
            }
            if((hero.heroPos.x>=627)&&(event.key.keysym.sym==SDLK_e))
            {
             GenererEnigme(&s);
             initialiser_enigme(&s);
             SDL_Event event1;
             while (keep)
/** Affichage **/
{
    while(SDL_PollEvent(&event1))
	{

		switch(event1.type)
		{
		case SDL_QUIT:

			keep=0;
		break;
        case SDL_KEYDOWN:
			switch (event1.key.keysym.sym)
			{

			case SDLK_a :
				if (s.right_answer==0)
                {
                    SDL_BlitSurface(win,NULL,screen,NULL);
                    SDL_Flip(screen);
                    SDL_Delay(3000);
                    keep=0;
                    printf("vrai");
                    ////////////////
                }
                else {
                    SDL_BlitSurface(loss,NULL,screen,NULL);
                    SDL_Flip(screen);
                    SDL_Delay(3000);
                    keep=0;
                    printf("faux");
                }

      		break;
            case SDLK_z :
                if (s.right_answer==1)
                {
                    SDL_BlitSurface(win,NULL,screen,NULL);
                    SDL_Flip(screen);
                    SDL_Delay(3000);
                    keep=0;
                    printf("vrai");
                }
                else {
                    SDL_BlitSurface(loss,NULL,screen,NULL);
                    SDL_Flip(screen);
                    SDL_Delay(3000);
                    keep=0;
                    printf("faux");
                }
            break;
            case SDLK_e:
                if (s.right_answer==2)
                {
                    SDL_BlitSurface(win,NULL,screen,NULL);
                    SDL_Flip(screen);
                    SDL_Delay(3000);
                    keep=0;
                    printf("vrai");
                }
                else {
                    SDL_BlitSurface(loss,NULL,screen,NULL);
                    SDL_Flip(screen);
                    SDL_Delay(3000);
                    keep=0;
                    printf("faux");
                }
            break;
            }
            break;
        }
        AfficherEnigme(&s,screen);
    }
    SDL_Flip(screen);

}
            }
            // end events
            // finally, update the screen :)
            SDL_Flip(screen);
            SDL_Delay(5);
        }
            d = e.enem.x-hero.heroPos.x;
            collision = collisionBB(hero,e);
        if(collision==1)
          e.vie-10;
        if(e.vie==0)
            done=0;

    }
}

void init_input(Input *I)
{
    I->left = 0;
    I->right = 0;
    I->down = 0;
    I->jump = 0;
    I->attack = 0;
}
void init_hero(Hero *h)
{

    h->allMvt = IMG_Load("hero_sprites.png");

    h->hpBars[0] = IMG_Load("hp_0.png");
    h->hpBars[1] = IMG_Load("hp_1.png");
    h->hpBars[2] = IMG_Load("hp_2.png");
    h->hpBars[3] = IMG_Load("hp_3.png");
    h->hpBars[4] = IMG_Load("hp_4.png");

    h->frame = 0;
    h->currentMode = 0;

    h->heroPos.x = 0;
    h->heroPos.y = 350;//ground

    h->hpBarPos.x = 0;
    h->hpBarPos.y = 0;

    h->velocity = 0;
    h->speed = 5;

    h->hp = 4;
    h->score = 0;

    h->xStep = 20;
    h->yStep = 10;

    setrects(h->rects);
}

void setrects(SDL_Rect *crop)
{
    int i;

    //idle right
    crop[0].x = 0;
    crop[0].y = 0;

    crop[0].w = 221;
    crop[0].h = 204;

    for (i = 1; i < frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 0;
    }

    //idle left
    crop[10].x = 0;
    crop[10].y = 204;

    crop[10].w = 221;
    crop[10].h = 204;

    for (i = 11; i < 2 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 204;
    }

    //run right
    crop[20].x = 0;
    crop[20].y = 408;

    crop[20].w = 221;
    crop[20].h = 204;

    for (i = 21; i < 3 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 408;
    }

    //run left
    crop[30].x = 0;
    crop[30].y = 612;

    crop[30].w = 221;
    crop[30].h = 204;

    for (i = 31; i < 4 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 612;
    }

    //jump right
    crop[40].x = 0;
    crop[40].y = 816;

    crop[40].w = 221;
    crop[40].h = 204;

    for (i = 41; i < 5 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 816;
    }

    //jump left
    crop[50].x = 0;
    crop[50].y = 1020;

    crop[50].w = 221;
    crop[50].h = 204;

    for (i = 51; i < 6 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1020;
    }

    //attack right
    crop[60].x = 0;
    crop[60].y = 1224;

    crop[60].w = 221;
    crop[60].h = 204;

    for (i = 61; i < 7 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1224;
    }

    //attack left
    crop[70].x = 0;
    crop[70].y = 1428;

    crop[70].w = 221;
    crop[70].h = 204;

    for (i = 71; i < 8 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1428;
    }

    //dead right
    crop[80].x = 0;
    crop[80].y = 1632;

    crop[80].w = 221;
    crop[80].h = 204;

    for (i = 81; i < 9 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1632;
    }

    //dead left
    crop[90].x = 0;
    crop[90].y = 1836;

    crop[90].w = 221;
    crop[90].h = 204;

    for (i = 91; i < 10 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 204;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1836;
    }
}

void afficher_Hero(Hero *h, SDL_Surface *screen, SDL_Surface *topBg, SDL_Surface *score)
{
    SDL_Rect test;
    test.x = 1700;
    test.y = 30;
    SDL_BlitSurface(topBg, NULL, screen, &h->hpBarPos);
    SDL_BlitSurface(h->hpBars[h->hp], NULL, screen, &h->hpBarPos);
    SDL_BlitSurface(score, NULL, screen, &test);
    SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
}

void idleAnimation(Hero *h)
{
    if (h->currentMode == 0)
    {
        if (h->frame < 0 || h->frame > 9)
        {
            h->frame = 0;
        }
        h->frame++;

        if (h->frame > frameNb - 1)
        {
            h->frame = 0;
        }
    }
    else if (h->currentMode == 1)
    {

        if (h->frame < 10 || h->frame > 19)
        {
            h->frame = 10;
        }
        h->frame++;

        if (h->frame > 19)
        {
            h->frame = 10;
        }
    }
}

void runAnimation(Hero *h)
{
    if (h->currentMode == 2)
    {
        if (h->frame < 20 || h->frame > 29)
        {
            h->frame = 20;
        }
        h->frame++;
        if (h->frame > 29)
        {
            h->frame = 20;
        }
    }
    else if (h->currentMode == 3)
    {
        if (h->frame < 30 || h->frame > 39)
        {
            h->frame = 30;
        }
        h->frame++;
        if (h->frame > 39)
        {
            h->frame = 30;
        }
    }
}

void jumpAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, int run)
{
    int i;
    if (h->currentMode == 4)
    {
        for (i = 40; i < 50; i++)
        {
            h->frame = i;

            if (i > 44)
            {
                h->heroPos.y += 25;
            }
            else
            {
                h->heroPos.y -= 25;
            }
            if (run == 1)
            {
                if (h->heroPos.x < 1700)
                {
                    h->heroPos.x += 25;
                }
            }
            SDL_BlitSurface(bg, NULL, screen, &bgPos);
            SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
            SDL_Flip(screen);
            SDL_Delay(15);
        }
    }
    else if (h->currentMode == 5)
    {
        for (i = 50; i < 60; i++)
        {
            h->frame = i;

            if (i > 54)
            {
                h->heroPos.y += 25;
            }
            else
            {
                h->heroPos.y -= 25;
            }

            if (run == 1)
            {
                h->heroPos.x -= 25;
            }
            SDL_BlitSurface(bg, NULL, screen, &bgPos);
            SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
            SDL_Flip(screen);
            SDL_Delay(15);
        }
    }
}

void attackAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos)
{
    int i;

    if (h->currentMode == 6)
    {
        for (i = 60; i < 69; i++)
        {
            h->frame = i;

            SDL_BlitSurface(bg, NULL, screen, &bgPos);
            SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
            SDL_Flip(screen);
            SDL_Delay(15);
        }
    }
    else if (h->currentMode == 7)
    {
        for (i = 70; i < 79; i++)
        {
            h->frame = i;

            SDL_BlitSurface(bg, NULL, screen, &bgPos);
            SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
            SDL_Flip(screen);
            SDL_Delay(15);
        }
    }
}

void jumpHeroMvt(Hero *hero, Input I, int *run)
{
    if (I.jump == 1)
    {
        if (I.right == 1)
        {
            hero->currentMode = 4;
            *run = 1;
        }
        else if (I.left == 1)
        {
            hero->currentMode = 5;
            *run = 1;
        }
        else
        {
            if (hero->currentMode == 0)
            {
                hero->currentMode = 4;
                *run = 0;
            }
            else if (hero->currentMode == 1)
            {
                hero->currentMode = 5;
                *run = 0;
            }
        }
    }
}

void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt, int comp)
{
    if (hero->currentMode == 2 || hero->currentMode == 3)
    {
        if (I.right == 1)
        {

            //hero->xStep = 0.5 * hero->velocity * 2.2 * 2.2 + hero->speed * 2.2;
            if (hero->heroPos.x < 1500)
            {
                hero->heroPos.x += 3;

            }
            if (hero->velocity < 8)
            {
                //hero->velocity += 0.5;
            }
        }

        if (I.left == 1)
        {
            //hero->xStep = 0.5 * hero->velocity * 2.2 * 2.2 + hero->speed * 2.2;
            hero->heroPos.x -= 3;
            if (hero->velocity < 8)
            {
                //hero->velocity += 0.5;
            }
        }
    }
    if (I.right == 0 && I.left == 0)
    {
        hero->velocity = 0;
    }
}

void deadAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos)
{
    int i;

    if (h->currentMode == 8)
    {
        for (i = 80; i < 89; i++)
        {
            h->frame = i;

            SDL_BlitSurface(bg, NULL, screen, &bgPos);
            SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
            SDL_Flip(screen);
            SDL_Delay(15);
        }
        h->currentMode = -1;
    }
    else if (h->currentMode == 9)
    {
        for (i = 90; i < 99; i++)
        {
            h->frame = i;

            SDL_BlitSurface(bg, NULL, screen, &bgPos);
            SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
            SDL_Flip(screen);
            SDL_Delay(15);
        }
        h->currentMode = -1;
    }
}

void updateHeroHealth(Hero *h, char *direction)
{
    if (h->hp > 0)
    {
        h->hp = h->hp - 1;
        if (h->hp == 0)
        {
            if (strcmp(direction, "right") == 0)
            {
                h->currentMode = 8;
            }
            else
            {
                h->currentMode = 9;
            }
        }
    }
}

/*void updateHeroScore(Hero *h, SDL_Surface **score, TTF_Font *police, SDL_Color color, char *scoreText, SDL_Surface *screen)
{
    SDL_Rect test;
    test.x = 1700;
    test.y = 30;
    h->score = h->score + 10;
    sprintf(scoreText, "Score: %d", h->score);
    *score = TTF_RenderText_Blended(police, scoreText, color);
}*/
int right=0;
int left=1;
int up=2;
int down=3;
int d;
int s1;
int s2;
/**
* @brief To initialize the Ennemi e .
* @param e the Ennemi
* @return Nothing
*/
void initEnnemi(Ennemi*e)
{
    //e->enemi[0]=IMG_Load("idl1.png");
    //e->enemi[1]=IMG_Load("idl2.png");
    e->enemi[0]=IMG_Load("R1.png");
    e->enemi[1]=IMG_Load("R2.png");
    e->enemi[2]=IMG_Load("R3.png");
    e->enemi[3]=IMG_Load("L1.png");
    //e->enemi[4]=IMG_Load("idl1.png");
    //e->enemi[5]=IMG_Load("idl2.png");
    e->enem.x=400;
    e->enem.y=370;
    e->vie=100;
    e->num=0;
    e->state=waiting;
    s1=300;
    s2=100;
}
/**
* @brief To show the Enemy .
* @param e the Ennemi
* @param screen is the screen
* @return Nothing
*/
void afficherEnnemi(Ennemi e, SDL_Surface * screen)
{
    SDL_BlitSurface(e.enemi[e.num],NULL,screen,&e.enem);
    //SDL_Flip(screen);

}
/**
* @brief To animate the enemy .
* @param e the Ennemi
* @return Nothing
*/
void animerEnnemi( Ennemi * e)
{
    if(e->direction==right)
    {
        if(e->num==3)
            e->num=0;
        else
            e->num++;
    }
    else if(e->direction==left)
    {
        if(e->num==4)
            e->num=3;
        //else                      // use this if you have more than one image in direct LEFT.
        //e->num++;
    }
    /*else if(e->direction==down)
    {
        if(e->num==5)
           e->num=4;
           else
               e->num++;
    }
    else if (e->direction==up)
    {
        if(e->num==5)
           e->num=4;
           else
               e->num++;
    }*/


}
/**
* @brief To move the enemy randomly .
* @param e the Ennemi
* @return Nothing
*/
void deplacer( Ennemi * e)
{
    /*if(e->enem.x>662)
        e->direction=down;*/
    /*if(e->enem.x<=0)
        e->direction=up;*/
    if(e->enem.x>=600)
        e->direction=left;
    if(e->enem.x<=400)
        e->direction=right;

    if(e->direction==right)
    {
        e->enem.x++;

    }
    else if(e->direction==left)
    {
        e->enem.x--;

    }
    else if(e->direction==down)
    {
        e->enem.y++;
    }
    else if(e->direction==up)
    {
        e->enem.y--;
    }

    /*if(right==1 )
    {
        right=0;
        e->enem.x++;
    }
    else if(left == 1)
    {
        left=0;
        e->enem.x--;
    }*/

}
/**
* @brief To move the enemy with AI.
* @param e the Ennemi
* @return Nothing
*/
void deplacerIA(Ennemi *e)
{
    switch(e->state)
    {
    case waiting:
        if(d>s1)
            e->state=waiting;
        else if(s2<d<=s1)
            e->state=following;
        break;
    case following:
        if(s2<d<=s1)
        {
            e->state=following;
            while(e->enem.x!=s1)
                e->enem.x++;
        }
        else if(0<d<=s2)
            e->state=attacking;
        break;
    case attacking:
        if(0<d<=s2)
        {
            e->state=attacking;
            while(e->enem.x!=s2)
                e->enem.x++;
        }
        else if(d<=0)
            e->state=waiting;
        break;

    }
}
/**
* @brief To detect if there is collision  .
* @param e the Ennemi
* @param p the personne
* @return variable of type int
*/
int collisionBB( Hero hero, Ennemi e)
{
    int collis;
    if((hero.heroPos.x+hero.heroPos.w<e.enem.x)||(hero.heroPos.x>e.enem.w+e.enem.x)||(hero.heroPos.y+hero.heroPos.h<e.enem.y)||(hero.heroPos.y>e.enem.h+e.enem.y))
        collis=0;
    else

        collis=1;

    return collis;
}
void AfficherEnigme(enigme * s,SDL_Surface * screen)
{

SDL_BlitSurface(s->background_e,NULL,screen,NULL);
SDL_BlitSurface(s->text_e,NULL,screen,&s->postext_e);
SDL_BlitSurface(s->text_question,NULL,screen,&s->postext_question);
SDL_BlitSurface(s->text_r1,NULL,screen,&s->postext_r1);
SDL_BlitSurface(s->text_r2,NULL,screen,&s->postext_r2);
SDL_BlitSurface(s->text_r3,NULL,screen,&s->postext_r3);




}

void initialiser_enigme(enigme *s)

{
SDL_Color couleurNoir={0,0,0};
s->background_e=IMG_Load("background_e.jpg");
/*e->posbackground_e.x=0;
e->posbackground_e.y=0;
e->posbackground_e.w=1000;
e->posbackground_e.h=1000;*/
if(s->background_e==NULL)
{
printf("unable to set enigme  background: %s\n",SDL_GetError());
//return 1;
}

s->police_e=TTF_OpenFont("arial.ttf",40);
s->text_e=TTF_RenderText_Blended(s->police_e,"You Shall not pass without knowledge",couleurNoir);
s->postext_e.x=150;
s->postext_e.y=50;
//e->postext_e.w=1000;
//e->postext_e.h=1000;
s->postext_question.x=100;
s->postext_question.y=200;
s->postext_r1.x=50;
s->postext_r2.x=300;
s->postext_r3.x=550;
s->postext_r3.y=400;
s->postext_r2.y=400;
s->postext_r1.y=400;



s->text_question = TTF_RenderText_Blended(s->police_e,s->question,couleurNoir);
s->text_r1 = TTF_RenderText_Blended(s->police_e,s->answer1,couleurNoir);
s->text_r2 = TTF_RenderText_Blended(s->police_e,s->answer2,couleurNoir);
s->text_r3 = TTF_RenderText_Blended(s->police_e,s->answer3,couleurNoir);


// initialisation des position question et rep 1,2,3
//e->number_questions=3;
}
/****************************************************************/
void GenererEnigme(enigme * s)
{
char nomfichier[10];
FILE *f;
// tirage aleatoire du num de question rand ( 1,2,3)
int j;
srand(time(NULL));

j= rand() % 3;
sprintf(nomfichier,"%d.txt",j);
f=fopen(nomfichier,"r");
fscanf(f,"%s %s %s %s %d",s->question,s->answer1,s->answer2,s->answer3,&s->right_answer);

fclose(f);
/*******************************************************************/
// lecture de fichier : on suppose rand = question 2
// il faut lire les ligne; de : 5*(num_question-1)  +1 jusq'à 5*(num_question-1)  +1 +4
}

