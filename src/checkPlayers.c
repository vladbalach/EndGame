#include "header.h"


static void keybords(int *x1, int *x2, int *y1, int *y2, int *running) {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if(event.key.keysym.sym == SDLK_w) 
                  if (*x1 > 0) *x1 = *x1 - 1; 
                if(event.key.keysym.sym == SDLK_a) 
                    if (*y1 > 0) *y1 = *y1 -1;
                if(event.key.keysym.sym == SDLK_s) 
                    if (*x1 < 3) *x1 = *x1 + 1;
                if(event.key.keysym.sym == SDLK_d) 
                   if (*y1 < 1) *y1 = *y1 + 1;
                if(event.key.keysym.sym == SDLK_UP) 
                    if (*x2 > 0) *x2 = *x2 - 1;
                if(event.key.keysym.sym == SDLK_RIGHT) 
                   if (*y2 < 1) *y2 = *y2 + 1;
                if(event.key.keysym.sym == SDLK_DOWN) 
                   if (*x2 < 3) *x2 = *x2 + 1;
                if(event.key.keysym.sym == SDLK_LEFT) 
                   if (*y2 > 0) *y2 = *y2 - 1;
                if(event.key.keysym.sym == SDLK_ESCAPE) *running = 0;
            }
            if(event.type == SDLK_KP_ENTER)  *running = 1;
    }
}

void printfRect(int x, int y, int w, int d, char *s, SDL_Renderer *renderer) {
    SDL_Rect rect = {(x * SIZE_OF_SYMBOL), (y * SIZE_OF_SYMBOL) , (w * SIZE_OF_SYMBOL),  (d * SIZE_OF_SYMBOL)};
    SDL_Rect rect2 = {((x * 4) * SIZE_OF_SYMBOL), (y * SIZE_OF_SYMBOL) , (w * SIZE_OF_SYMBOL),  (d *SIZE_OF_SYMBOL)};
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, s);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect2);
}

void printfRect2(int x, int y, int w, int d, char *s, SDL_Renderer *renderer) {
    SDL_Rect rect = {(x * SIZE_OF_SYMBOL), (y * SIZE_OF_SYMBOL) , (w * SIZE_OF_SYMBOL), (d * SIZE_OF_SYMBOL)};
    SDL_Rect rect2 = {((x + 27) * SIZE_OF_SYMBOL), (y * SIZE_OF_SYMBOL) , (w * SIZE_OF_SYMBOL), (d * SIZE_OF_SYMBOL)};
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, s);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect2);
}

void printfRect3(int x, int y, int w, int d, char *s, SDL_Renderer *renderer) {
    SDL_Rect rect = {(x * SIZE_OF_SYMBOL), (y * SIZE_OF_SYMBOL) , (w * SIZE_OF_SYMBOL),  (d * SIZE_OF_SYMBOL)};
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, s);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
}

void mx_print(char **l,char**s,int *x, int *y, SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    printfRect(9,3,12,4,s[0],renderer);
    printfRect(9,9,12,4,s[1],renderer);
    printfRect(9,15,12,4,s[2],renderer);
    printfRect(9,21,12,4,s[3],renderer);
    printfRect2(9,27,4,4,l[0],renderer);
    printfRect2(17,27,4,4,l[1],renderer);
    if (x[0] == 0) printfRect3(9,3,12,4,l[2],renderer);
    if (x[0] == 1) printfRect3(9,9,12,4,l[2],renderer);
    if (x[0] == 2) printfRect3(9,15,12,4,l[2],renderer);
    if (x[0] == 3) printfRect3(9,21,12,4,l[2],renderer);
    if (x[1] == 0) printfRect3(36,3,12,4,l[2],renderer);
    if (x[1] == 1) printfRect3(36,9,12,4,l[2],renderer);
    if (x[1] == 2) printfRect3(36,15,12,4,l[2],renderer);
    if (x[1] == 3) printfRect3(36,21,12,4,l[2],renderer);
    if (y[0] == 0) printfRect3(9,27,4,4,l[2],renderer);
    if (y[1] == 0) printfRect3(36,27,4,4,l[2],renderer);
    if (y[0] == 1) printfRect3(17,27,4,4,l[2],renderer);
    if (y[1] == 1) printfRect3(44,27,4,4,l[2],renderer);
}

void mx_checkPlayers(/*t_player *player, t_player *player2, *//*SDL_Window *window*/SDL_Renderer *renderer) {
    /*SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);*/
    char *s[] = {"sprites/spaceStation_022.png", "sprites/spaceStation_018.png", "sprites/spaceStation_023.png", "sprites/spaceStation_019.png"};
    char *l[] = {"sprites/environment_12.png", "imgs/1.png","imgs/0427.png_860.png"};
    int x[] = {0, 0, -1};
    int y[] = {0, 0};
    while(x[2] == -1) { 
        SDL_RenderClear(renderer);
        mx_print(l, s, x, y,renderer);
        SDL_RenderPresent(renderer);   
        keybords(&x[0], &x[1], &y[0], &y[1], &x[2]);
    }
    
    //SDL_DestroyRenderer(renderer);
    
}