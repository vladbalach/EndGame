#include "header.h"
int main() {
    bool running = true;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = 
    SDL_CreateWindow("Hello, SDL2", 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, WIDTH_PIX, HEIGHT_PIX, 
    SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("OpenSansBold.ttf",20);
    if (font == 0) {
          printf("%s",TTF_GetError());
          exit(1);
    };
    SDL_Color color = {0, 255, 0, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Some words!", color);
    SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {0,0,100,100};
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, "sprites/crate_01.png");
    
    //SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
    //SDL_FreeSurface(textSurface);
    textSurface = 0;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
        }
        //SDL_RenderCopy(renderer, imgBorder, NULL, &textRect);
        SDL_RenderCopy(renderer, text, NULL, &textRect);
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(text);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}