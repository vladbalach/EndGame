#include "header.h"
void drawTexturedSquad(int x, int y, int w, int h, char* texture, SDL_Renderer *renderer) {
    SDL_Rect customize_backgroundRect = {x, y, w, h};
    SDL_Texture *customize_imgBackground = IMG_LoadTexture(renderer, texture);
    SDL_RenderCopy(renderer, customize_imgBackground, NULL, &customize_backgroundRect);
    SDL_DestroyTexture(customize_imgBackground);
}

int showStartMenu(SDL_Renderer *renderer) {
    bool running = true;
    /*SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = 
    SDL_CreateWindow("Hello, SDL2", 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, WIDTH_PIX, HEIGHT_PIX, 
    SDL_WINDOW_OPENGL);*/
    /*SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);*/
    SDL_Event event;
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("ttf/OpenSansBold.ttf",96);
    if (font == 0) {
          printf("%s",TTF_GetError());
          exit(1);
    };
    SDL_Color color = {0, 255, 0, 255};

    //Customize panel
    SDL_Rect customize_backgroundRect = {150, 400, 500, 700};
    SDL_Texture *customize_imgBackground = IMG_LoadTexture(renderer, "sprites/border2.png");


    //background 
    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};

    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/border2.png");

    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
        }
        //SDL_RenderCopy(renderer, imgBorder, NULL, &textRect);
       
        //SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
       // drawTexturedSquad(150, 400, 500, 700, "sprites/border2.png", renderer);
        SDL_RenderCopy(renderer, customize_imgBackground, NULL, &customize_backgroundRect);
       // drawText(color, WIDTH_PIX/4, 150, "Name of game!", renderer,  96);
        drawText(color, 300, 300, "char *text", renderer,  32, font);

        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(imgBackground);
    /*SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();*/
    return 1;
}