#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "header.h"
#define SIZE_OF_SYMBOL 64
#define HEIGHT_SYMB 40 // MAP SYMBOLS
#define WIDTH_SYMB 60 
#define WIDTH_PIX (WIDTH_SYMB * SIZE_OF_SYMBOL)
#define HEIGHT_PIX (HEIGHT_SYMB * SIZE_OF_SYMBOL)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Draw points with random colors and positions

void initMap(char *mass) {
    for (int i = 0; i < HEIGHT_SYMB; i++) {
        for (int j = 0; j < WIDTH_SYMB; j++) {
            if ((i == 0) || (j == 0) 
            || (i == HEIGHT_SYMB-1) || (j == WIDTH_SYMB-1))
                *(mass + WIDTH_SYMB * i + j) = '0';
        else {
            *(mass + WIDTH_SYMB * i + j) = ' ';
        }
        }
    }
}

void drawPlayer(t_player *player, SDL_Rect *rect, SDL_Renderer *render) {
    rect->x = 10 * SIZE_OF_SYMBOL;
    rect->y = 10 * SIZE_OF_SYMBOL;
    SDL_RenderFillRect(render, rect);
}
int main(int argc, char **argv)
{
    char MAP[HEIGHT_SYMB][WIDTH_SYMB];
    t_player player1;
    player1.x = 10;
    player1.y = 10; 
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
   
    // Create a SDL window
    SDL_Window *window = 
    SDL_CreateWindow("Hello, SDL2", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, WIDTH_PIX, HEIGHT_PIX, 
        SDL_WINDOW_OPENGL);
    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, "imgs/1.png");
    bool running = true;
    SDL_Event event;
    int x = 0;
    int dx = 6;
    SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    initMap(&MAP[0][0]);
    while(running)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0 , 255);
        for (int i = 0; i < HEIGHT_SYMB; i++){
            for (int j = 0; j < WIDTH_SYMB; j++) {
                if (MAP[i][j] == '0') {
                    rect.x = j * SIZE_OF_SYMBOL;
                    rect.y = i * SIZE_OF_SYMBOL;
                    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
                    //SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 0 , 255);
        drawPlayer(&player1, &rect, renderer);
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                
                running = false;
            }
            if (event.type == SDL_KEYDOWN)
	        {
                //if (event.key.keysym.sym == SDLK_UP)
                    //if(checkMove(UP, player1, mass))
	        }
        }
        SDL_RenderPresent(renderer);
    }
    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// #define IMG_PATH "1.png"
// static const int width = 800;
// static const int height = 600;
// // Draw points with random colors and positions
// int main(int argc, char **argv)
// {int w, h;
//    // Initialize SDL
//    SDL_Init(SDL_INIT_VIDEO);
//    // Create a SDL window
//    SDL_Window *window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 
//    SDL_WINDOW_OPENGL);
//    // Create a renderer (accelerated and in sync with the display refresh rate)
//    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//    bool running = true;
//    SDL_Event event;
//    int x = 0;
//    int dx = 6;
//     int dy = 6;
//    int y = 0;
//    while(running)
//    {
       
//         SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
//         SDL_RenderClear(renderer);
//         SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
//         SDL_Texture *img = IMG_LoadTexture(renderer, "imgs/1.png");
//         SDL_Rect rect = {x, y, 25, 25};
//         SDL_RenderCopy(renderer, img, NULL, &rect);
//         SDL_RenderPresent(renderer);
//         while(SDL_PollEvent(&event))
//         {
//             if(event.type == SDL_QUIT)
//             {
//                running = false;
//             }
//        }
      
//        //SDL_RenderPresent(renderer);
//    }
//    // Release resources
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
// }