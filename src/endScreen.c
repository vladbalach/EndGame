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
    IMG_Quit();
    return 0;
}