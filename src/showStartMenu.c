#include "header.h"
int showStartMenu() {
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
    TTF_Font *font = TTF_OpenFont("ttf/OpenSansBold.ttf",96);
    if (font == 0) {
          printf("%s",TTF_GetError());
          exit(1);
    };
    SDL_Color color = {0, 255, 0, 255};
    //Customize panel
    SDL_Rect customize_backgroundRect = {150, 400, 500, 700};
    SDL_Texture *customize_imgBackground = IMG_LoadTexture(renderer, "sprites/border2.png");

    //text game Name
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Name Of Game!", color);
    SDL_Texture *textureGameName = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {WIDTH_PIX/4,150,WIDTH_PIX/2,100};

    //text 
    color.r = 0;
    color.g = 0;
    color.b = 255;
    SDL_Surface *sur_textCustomize = TTF_RenderText_Solid(font, "Customize", color);
    SDL_Texture *texture_Customize = SDL_CreateTextureFromSurface(renderer, sur_textCustomize);
    SDL_Rect rect_textCustomize = {WIDTH_PIX/4,150,WIDTH_PIX/2,100};

    //background 
    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/border2.png");
    //SDL_SetRenderDrawColor(renderer, 0,255,0,255);
    SDL_QueryTexture(textureGameName, NULL, NULL, &textRect.w, &textRect.h);
    SDL_FreeSurface(textSurface);
    textSurface = 0;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
        }
        //SDL_RenderCopy(renderer, imgBorder, NULL, &textRect);
       
        //SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
       
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        SDL_RenderCopy(renderer, textureGameName, NULL, &textRect);
        SDL_RenderCopy(renderer, customize_imgBackground, NULL, &customize_backgroundRect);
        SDL_RenderCopy(renderer, customize_imgBackground, NULL, &rect_textCustomize);
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(textureGameName);
    SDL_DestroyTexture(imgBackground);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}