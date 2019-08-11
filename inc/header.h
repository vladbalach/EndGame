#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
    int x;
    int y;
    int cloneX;
    int cloneY;
    int dx;
    int dy;
    char ch;
    char chClone;
    char *pathToTexture;
} t_player;

/*
0 - border block
1 - unvisible block
A - player 1
B - player 2
a - clone 1
b - clone 2
 */
void mx_move(t_player* player, char *MAP);
void checkMove(t_player *player, char* mass, int width);
void redrawMap(SDL_Renderer *render, char* MAP);
void drawMap( SDL_Renderer *render, char* MAP);

#endif