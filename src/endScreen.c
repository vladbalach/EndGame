#include "header.h"

int endScreen(t_player *player, SDL_Renderer *renderer) {
    bool running = true;
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
    // Again rect
    SDL_Rect againBackground = {300, 800, 450, 150};
    SDL_Texture *imgAgainBackground = IMG_LoadTexture(renderer, "sprites/again_button2.png");
    // Quit rect
    SDL_Rect quitBackground = {1100, 800, 450, 150};
    SDL_Texture *imgQuitBackground = IMG_LoadTexture(renderer, "sprites/quit2.png");

    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/end_background.png");
    while(running) {
        
        while(SDL_PollEvent(&event)) {
            if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            // if(event.key.keysym.sym == SDLK_ESCAPE)    
        }
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        SDL_RenderCopy(renderer, imgAgainBackground, NULL, &againBackground);
        SDL_RenderCopy(renderer, imgQuitBackground, NULL, &quitBackground);
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    IMG_Quit();
    return 0;
}