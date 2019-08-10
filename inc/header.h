#ifndef HEADER_H
#define HEADER_H

typedef struct s_player {
    int x;
    int y;
    int cloneX;
    int cloneY;
    int dx;
    int dy;
} t_player;
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define SIZE_OF_SYMBOL 32
#define HEIGHT_SYMB 40 // MAP SYMBOLS
#define WIDTH_SYMB 60 
#define WIDTH_PIX (WIDTH_SYMB * SIZE_OF_SYMBOL)
#define HEIGHT_PIX (HEIGHT_SYMB * SIZE_OF_SYMBOL)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
/*
0 - border block
1 - unvisible block */


#endif