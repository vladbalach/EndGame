#include "header.h"

void initPlayers(t_player **player1, t_player **player2) {
    t_player *players1 = (t_player*) malloc(sizeof(t_player) * 100000);
    t_player *players2 = (t_player*) malloc(sizeof(t_player) * 100000);
    players1->x = WIDTH_SYMB / 4 - 1;
    players1->y =  HEIGHT_SYMB - 2;
    players1->cloneY = 1;
    players1->ch = 'A';
    players1->chClone = 'a';
    players1->pathToTexture = (char*) malloc (100);
    players1->pathToTexture = "sprites/playerShip2_red.png";
    players1->speed = 1;
    players2->bulletSpeed = players1->bulletSpeed = 0.35;
    players2->coolDown = players1->coolDown  = 180000;
    players2->ch = 'B';
    players2->chClone = 'b';
    players2->x = WIDTH_SYMB / 4 * 3 - 1 ;
    players2->y = HEIGHT_SYMB - 2; 
    players2->speed = 1;
    players2->cloneY = 1;
    players2->pathToTexture = (char*) malloc (100);
    players2->pathToTexture = "sprites/playerShip1_blue.png";
    players1->cloneX = players2->x + 1;
    players2->cloneX = players1->x + 1;
    players1->pathToBulletTexture = (char*) malloc (100);
    players1->pathToBulletTexture = "bull_blue2.png";
    players2->pathToBulletTexture = (char*) malloc (100);
    players2->pathToBulletTexture = "bull_red.png.png";
    *player1 = players1;
    *player2 = players2;
}