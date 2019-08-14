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
                if(event.key.keysym.sym == SDLK_RETURN) *running = 3;
                if(event.key.keysym.sym == SDLK_ESCAPE)  *running = 6;
            }
    }
}

void printfRect(int x, int y, int w, int d, char *s, SDL_Renderer *renderer) {
    SDL_Rect rect = {(x * SIZE_OF_SYMBOL + 20), (y * SIZE_OF_SYMBOL + 20) , (w * SIZE_OF_SYMBOL - 40),  (d * SIZE_OF_SYMBOL - 40)};
    SDL_Rect rect2 = {((x * 4) * SIZE_OF_SYMBOL + 20), (y * SIZE_OF_SYMBOL + 20) , (w * SIZE_OF_SYMBOL - 40),  (d *SIZE_OF_SYMBOL - 40)};
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, s);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect2);
    SDL_DestroyTexture(imgBorder);
}

void printfRect2(int x, int y, int w, int d, char *s, SDL_Renderer *renderer) {
    SDL_Rect rect = {(x * SIZE_OF_SYMBOL +20), (y * SIZE_OF_SYMBOL+20) , (w * SIZE_OF_SYMBOL-40), (d * SIZE_OF_SYMBOL -40)};
    SDL_Rect rect2 = {((x + 27) * SIZE_OF_SYMBOL+20), (y * SIZE_OF_SYMBOL+20) , (w * SIZE_OF_SYMBOL-40), (d * SIZE_OF_SYMBOL-40)};
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, s);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect2);
    SDL_DestroyTexture(imgBorder);
}

void printfRect3(int x, int y, int w, int d, char *s, SDL_Renderer *renderer) {
    SDL_Rect rect = {(x * SIZE_OF_SYMBOL), (y * SIZE_OF_SYMBOL) , (w * SIZE_OF_SYMBOL),  (d * SIZE_OF_SYMBOL)};
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, s);
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    SDL_DestroyTexture(imgBorder);
}

void mx_print(char **l,char**s,int *x, int *y, SDL_Renderer *renderer){
    printfRect3(0, 0, WIDTH_SYMB, HEIGHT_SYMB, s[4],renderer);
    printfRect(9, 5,12,4,s[0],renderer);
    printfRect(9,11,12,4,s[1],renderer);
    printfRect(9, 16,12,4,s[2],renderer);
    printfRect(9, 21,12,4,s[3],renderer);
    printfRect2(9, 27,4,4,l[0],renderer);
    printfRect2(17,27,4,4,l[1],renderer);
    if (x[0] == 0) printfRect3(9,5,12,4,l[2],renderer);
    if (x[0] == 1) printfRect3(9,11,12,4,l[2],renderer);
    if (x[0] == 2) printfRect3(9,16,12,4,l[2],renderer);
    if (x[0] == 3) printfRect3(9,21,12,4,l[2],renderer);
    if (x[1] == 0) printfRect3(36,5,12,4,l[5],renderer);
    if (x[1] == 1) printfRect3(36,11,12,4,l[5],renderer);
    if (x[1] == 2) printfRect3(36,16,12,4,l[5],renderer);
    if (x[1] == 3) printfRect3(36,21,12,4,l[5],renderer);
    if (y[0] == 0) printfRect3(9,27,4,4,l[3],renderer);
    if (y[1] == 0) printfRect3(36,27,4,4,l[4],renderer);
    if (y[0] == 1) printfRect3(17,27,4,4,l[3],renderer);
    if (y[1] == 1) printfRect3(44,27,4,4,l[4],renderer);
}

 void mx_TTF(t_player *player1, t_player *player2, SDL_Renderer *renderer) {
     if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font_Customize = TTF_OpenFont("ttf/ofont.ru_Fixedsys.ttf",72);
    SDL_Color color = {0, 255, 0, 255};
    drawText(color, SIZE_OF_SYMBOL * 11, SIZE_OF_SYMBOL * 1, player1->name, renderer, font_Customize);
    color.r = 255;
    drawText(color, SIZE_OF_SYMBOL * 38, SIZE_OF_SYMBOL * 1, player2->name, renderer, font_Customize);
    void TTF_CloseFont(TTF_Font *font_Customize);
    void TTF_Quit();
 }

void mx_TTF2(char *a, char *b, SDL_Renderer *renderer) {
     if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font_Customize = TTF_OpenFont("ttf/ofont.ru_Fixedsys.ttf",72);
    SDL_Color color = {0, 255, 0, 255};
    drawText(color, SIZE_OF_SYMBOL * 11, SIZE_OF_SYMBOL * 36, a, renderer, font_Customize);
    color.r = 255;
    drawText(color, SIZE_OF_SYMBOL * 38, SIZE_OF_SYMBOL * 36, b, renderer, font_Customize);
    void TTF_CloseFont(TTF_Font *font_Customize);
    void TTF_Quit();
 }

void borders(char *a,char *d, int *running, int *b) {
    SDL_Event Event;
    while(SDL_PollEvent(&Event)){
        if(Event.type == SDL_KEYDOWN) {
            if (*b < 10) { 
                if( (Event.key.keysym.sym>= SDLK_a ) && (Event.key.keysym.sym <= SDLK_z ) ){
                    *a =  (char)(Event.key.keysym.sym - SDLK_a + 'a');
                    *b = *b +1;
                }
            }
            if (*b > 0) {
                if (Event.key.keysym.sym == SDLK_BACKSPACE) {
                    *d = '\0';
                    *b = *b - 1;
                }
            }
            if(Event.key.keysym.sym == SDLK_RETURN)  *running = *running -1;
            if(Event.key.keysym.sym == SDLK_ESCAPE)  *running = 0;
        
    }
    }
}


int mx_checkPlayers(t_player **player1, t_player **player2,SDL_Renderer *renderer) {
    char *s[] = {"sprites/playerShip2_blue.png", "sprites/enemyBlue2.png", "sprites/playerShip1_red.png", "sprites/spaceship_red.png", "sprites/darkPurple.png"};
    char *l[] = {"sprites/bull_red.png", "sprites/bull_blue2.png","sprites/ramka1.png", "sprites/ramka2.png","sprites/ramka3.png", "sprites/ramka4.png"};
    int x[] = {0, 0, -1};
    int y[] = {0, 0};
    int b = 7;
    char d[11] = "Player1\0\0\0\0";
    char e[11] = "Player2\0\0\0\0";
    while(x[2] == -1) { 
        SDL_RenderClear(renderer);
        mx_print(l, s, x, y,renderer);
        mx_TTF(*player1, *player2, renderer);
       // mx_TTF2(d,e,renderer);
        SDL_RenderPresent(renderer);  
       // borders(d);

        keybords(&x[0], &x[1], &y[0], &y[1], &x[2]);
    }  
     while(x[2] == 3) {
        SDL_RenderClear(renderer);
        mx_print(l, s, x, y,renderer);
        mx_TTF(*player1, *player2, renderer);
        mx_TTF2(d,e,renderer);
        borders(&d[b],&d[b-1], &x[2],&b);
        SDL_RenderPresent(renderer);  
     }
     b = 7; 
     while(x[2] == 2) {
        SDL_RenderClear(renderer);
        mx_print(l, s, x, y,renderer);
        mx_TTF(*player1, *player2, renderer);
        mx_TTF2(d,e,renderer);
        borders(&e[b],&e[b-1], &x[2],&b);
        SDL_RenderPresent(renderer);  
     }

     char *o = strdup(d);
     char *t = strdup(e);

    (*player1)->pathToTexture = s[x[0]];
    (*player1)->pathToBullet = l[y[0]];
    (*player2)->pathToTexture = s[x[1]];
    (*player2)->pathToBullet = l[y[1]];
    (*player1)->name = o;
    (*player2)->name = t;
    return x[2];
}
