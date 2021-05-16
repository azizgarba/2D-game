#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_video.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include<string.h>
#include<math.h>
#include "menu.h"
#include "globale.h"
#include "options.h"
#include "events.h"
#include<time.h>
//This is sad to witness.
/*typedef struct
{
    SDL_Surface *bg;
    SDL_Rect posbg;
    SDL_Rect camera_pos;
    SDL_Rect posbg1;
    SDL_Rect camera_pos1;

} Background;*/
typedef struct
{
SDL_Surface *image; /*!< Surface. */
SDL_Rect camera; /*!< Rectangle*/
}
background;
typedef enum STATE STATE;
enum STATE {waiting,following,attacking};
/**
* @struct Ennemi
* @brief struct for Ennemi
*/
typedef struct
{
    int vie;
    SDL_Surface *enemi[4]; /*!< tableau de Surface*/
    SDL_Rect enem; /*!< Rectangle*/
    int direction; /*!< direction de l'ennemi*/
    int num; /*!< num d'animation*/
    STATE state; /*!< l'etat de l'ennemi*/
} Ennemi;
typedef struct
{
    SDL_Surface* mini_imag;
    SDL_Surface* bon_homme;
    SDL_Rect posmini_imag;
    SDL_Rect posbon_homme;
} minimap;
typedef struct Map
{
    char Path[50];
    SDL_Rect Obsacles[100];
    SDL_Rect Secondary[200];
} Map;
typedef struct
{
    SDL_Surface *allMvt;
    SDL_Surface *hpBars[5];
    SDL_Rect heroPos;
    SDL_Rect rects[100];
    SDL_Rect hpBarPos;

    int frame;
    float xStep, yStep;
    float velocity, speed;
    int currentMode;
    int hp;
    int score;

} Hero;

typedef struct
{
    int left, right, jump, attack, down;

} Input;

typedef struct Time
{

    SDL_Surface *msg,*txt;

    TTF_Font *font;

    int time,score;

    SDL_Rect r;

    char timeString[10],scoreString[10];



} Time;

////////////////////////////////////// Enigme sans fichier

/*typedef struct
{
    SDL_Surface *bg, *butt_play, *bse, *instruc;
    SDL_Rect x_bp, x_bse, x_p;
    ///////////////////////////////
    SDL_Surface *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8, *c9, *c10;
    SDL_Rect x_c;
    ///////////////////////////////
    SDL_Surface *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9;
    SDL_Rect x_po;
    ///////////////////////////////
    SDL_Surface *yw, *yl;
    /////////////////////////////
    SDL_Surface *pl1, *pl2, *pl3;
    SDL_Surface *trp1, *trp2, *trp3;
    SDL_Rect x_trp1, x_trp2, x_trp3;

} enigme;

enigme *generer();
void afficherEnigme(enigme *e);
int algoenigme(enigme *e);
void showinstructions(enigme *e);*/
//////////////////////////////////////

/*typedef struct
{
    SDL_Surface *background;
    char question[50],rp1[15],rp2[15],rp3[15];
    int solution;//imene
} Enigme;*/
typedef struct
{
   SDL_Surface *background_e;
SDL_Rect posbackground_e;
SDL_Surface *text_e;
SDL_Rect postext_e;
SDL_Surface *text_question;
SDL_Rect postext_question;
SDL_Surface *text_r1;
SDL_Rect postext_r1;
SDL_Surface *text_r2;
SDL_Rect postext_r2;
SDL_Surface *text_r3;
SDL_Rect postext_r3;
  TTF_Font *police_e;
    char question[60];
    char answer1[50],answer2[50], answer3[50];
    //char answer;
    int right_answer;
   // int number_questions;
}enigme ;


typedef struct
{
    SDL_Surface *bg, *butt_play, *butt_options, *butt_quit, *butt_load, *butt_cr;
    SDL_Rect x_options, x_quit, x_load, x_cr, x_logo;
    //
    SDL_Surface *invis_butt1, *invis_butt2, *invis_butt3, *invis_butt4, *invis_butt5;
    SDL_Rect x_invis_butt1, x_invis_butt2, x_invis_butt3, x_invis_butt4, x_invis_butt5;
}Menu;
//????????????????????????????????????????????
Menu *initMenu();

void drawMenu(Menu *m);
void mainprogEvents(Menu *m);




SDL_Surface* screen,*texte;
SDL_Surface* switchFullScreen();

extern int right;
extern int left;
extern int up;
extern int down;
extern int d;
extern int s1;
extern int s2;
///////////////////
void init_background(background* bg,char image[], int x, int y, int w, int h);
void affiche_background(background* bg, SDL_Surface *ecran, SDL_Rect bg1);
void scrolling (SDL_Rect* camera, int speed,int x, int l);
///////////////////
/*void initBack(Background *b);
void afficherBack(Background b,SDL_Surface *screen);
void scrolling(Background *b,int direction1,int pasAvancement);*/
void ham(SDL_Surface *screen);
options *initOptions();

void Drawoptions(options *Op);

void init_input(Input *I);
void setrects(SDL_Rect *crop);
void init_hero(Hero *h);
void afficher_Hero(Hero *h, SDL_Surface *screen, SDL_Surface *topBg, SDL_Surface *score);

void idleAnimation(Hero *h);
void runAnimation(Hero *h);
void jumpAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, int run);
void attackAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos);

void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt, int comp);

void jumpHeroMvt(Hero *hero, Input I, int *run);
void deadAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos);

void updateHeroHealth(Hero *h, char *direction);
void updateHeroScore(Hero *h, SDL_Surface **score, TTF_Font *police, SDL_Color color, char *scoreText, SDL_Surface *screen);
void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
void deplacerIA(Ennemi *e);
int collisionBB( Hero p, Ennemi e);
void initialiser_enigme(enigme *s);
void AfficherEnigme(enigme * s,SDL_Surface * screen);
void GenererEnigme(enigme * s) ;





#endif // HEAD_H_INCLUDED
