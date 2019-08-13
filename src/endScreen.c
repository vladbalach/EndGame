#include "header.h"
int endScreen(int player) {
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
        exit(1);
    }
    TTF_Font *font = TTF_OpenFont("ttf/OpenSansBold.ttf",48);
    if (font == 0) {
          printf("%s",TTF_GetError());
          exit(1);
    };

    while(running) {

        while(SDL_PollEvent(&event)) {
            if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
        }
        //SDL_RenderCopy(renderer, imgBorder, NULL, &textRect);
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}