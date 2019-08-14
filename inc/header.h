#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdbool.h>
#include <time.h>
#include <fcntl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#define SIZE_OF_SYMBOL 32
#define HEIGHT_SYMB 39 // MAP SYMBOLS
#define WIDTH_SYMB 60 
#define WIDTH_PIX (WIDTH_SYMB * SIZE_OF_SYMBOL)
#define HEIGHT_PIX (HEIGHT_SYMB * SIZE_OF_SYMBOL)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

typedef struct s_player {
    float x;
    float y;
    float cloneX;
    float cloneY;
    float dx;
    float dy;
    float speed;
    char ch;
    char chClone;
    float bulletSpeed; // Скорость снаряда
    int coolDown; //gthезарядка
    int games;
    int win;
    char *name;
    char *pathToTexture;
    char *pathToBullet;
    int health;
} t_player;

typedef struct s_bullet {
    float x;
    float y;
    float dx;
    float dy;
    float cloneX;
    float cloneY;
    char ch;
    struct s_bullet *next;
} t_bullet;
/*
0 - border block
1 - unvisible block
A - player 1
B - player 2
a - clone 1
b - clone 2
 */

//PLAYER
void drawPlayer(t_player *player, SDL_Renderer *render);
void mx_move(t_player* player, char *MAP);
void checkMove(t_player *player, char* mass, int width);
void redrawMap(SDL_Renderer *render, t_player *player1, t_player *player2, char* MAP);
void drawMap( SDL_Renderer *render, char* MAP);
void check_x(t_player *player, char* mass, int width);
void check_y(t_player *player, char* mass, int width);
void initPlayers(t_player **player1, t_player **player2);

//GENERAL
void drawText(SDL_Color color, int x, int y, char *text, SDL_Renderer *renderer, TTF_Font *font);

//MAP
void initMap(char *mass);

//SCREENS
int showStartMenu(SDL_Renderer *renderer, t_player *player1, t_player *player2);
void mx_checkPlayers(/*t_player *player, t_player *player2, *//*SDL_Window *window*/SDL_Renderer *renderer);
int startHard(t_player *player1, t_player *player2, t_player *winPlayer, SDL_Renderer *renderer);
int endScreen(t_player *player, SDL_Renderer *renderer);
//BULLETS
void clearBulletList(t_bullet **list, char* MAP);
t_bullet *createBullet(float x, float y, float dx, float dy, char ch, char *MAP);

void mx_push_front(t_bullet **list, float x, float y, float dx,float dy, char ch,  char *MAP);
int moveBullet(t_bullet **bullet, char *MAP);
void mx_pop_back(t_bullet **list);
void mx_pop_index(t_bullet **list, int index);
void mx_pop_front(t_bullet **list);
#endif