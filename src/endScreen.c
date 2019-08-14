#include "header.h"

int endScreen(t_player *player, SDL_Renderer *renderer) {
    bool running = true;
    SDL_Event event;
    int indexActive = 5;
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(1);
    }
    TTF_Font *font = TTF_OpenFont("ttf/ofont.ru_Fixedsys.ttf",48);
    if (font == 0) {
          printf("%s",TTF_GetError());
          exit(1);
    };
     SDL_Color color = {255, 255, 0, 255};
    //Border 1
    SDL_Rect border1 = {290, 795, 380, 127};
    SDL_Texture *border11 = IMG_LoadTexture(renderer, "sprites/ramka1.png");
    //Border 2
    SDL_Rect border2 = {1090, 795, 380, 127};
    SDL_Texture *border22 = IMG_LoadTexture(renderer, "sprites/ramka4.png");
    // Again rect
    SDL_Rect againBackground = {300, 800, 360, 120};
    SDL_Texture *imgAgainBackground = IMG_LoadTexture(renderer, "sprites/again_button2.png");
    // Quit rect
    SDL_Rect quitBackground = {1100, 800, 360, 120};
    SDL_Texture *imgQuitBackground = IMG_LoadTexture(renderer, "sprites/quit2.png");
    //Background
    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/end_background.png");

    
    while(running) {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
    SDL_RenderCopy(renderer, imgAgainBackground, NULL, &againBackground);
    SDL_RenderCopy(renderer, imgQuitBackground, NULL, &quitBackground);
        
        drawText(color, 600, 100, player->name, renderer,font);
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) { 
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                if(event.key.keysym.sym == SDLK_RIGHT) {
                    if (indexActive == 5) indexActive = 0;
                }
                if(event.key.keysym.sym == SDLK_LEFT) {
                    if (indexActive == 0) indexActive = 5;
                }
                if(event.key.keysym.sym == SDLK_RETURN) {
                    return indexActive;
                }
            }
            
        }
            if (indexActive == 5) {
                SDL_RenderCopy(renderer, border11, NULL, &border1);
                
            }
            if (indexActive == 0) {
                SDL_RenderCopy(renderer, border22, NULL, &border2);
            }
            
        
       
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    
    IMG_Quit();
    return 0;
}