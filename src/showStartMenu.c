#include "header.h"
void drawTexturedSquad(int x, int y, int w, int h, char* texture, SDL_Renderer *renderer) {
    SDL_Rect customize_backgroundRect = {x, y, w, h};
    SDL_Texture *customize_imgBackground = IMG_LoadTexture(renderer, texture);
    SDL_RenderCopy(renderer, customize_imgBackground, NULL, &customize_backgroundRect);
    SDL_DestroyTexture(customize_imgBackground);
}

int showStartMenu(SDL_Renderer *renderer) {
    bool running = true;
    SDL_Event event;
    int indexActive = 1;//1 - Ez,2-Hard,3-Cust,4-Score 
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    //TTF_Font *font_GameName = TTF_OpenFont("ttf/OpenSansBold.ttf",96);
    TTF_Font *font_Customize = TTF_OpenFont("ttf/OpenSansBold.ttf",64);
    /*if (font_GameName == 0) {
          printf("%s",TTF_GetError());
          exit(1);
    };*/
    SDL_Color color = {255, 255, 0, 255};
    //Customize panel
    SDL_Rect customize_backgroundRect = {150, 400, 500, 700};
    SDL_Texture *customize_imgBackground = IMG_LoadTexture(renderer, "sprites/border2.png");


    //background 
    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/border2.png");

    while(running) {
        color.r = 255;
        color.g = 255;
        color.b = 0;
        color.a = 255;
        while(SDL_PollEvent(&event)) {
              if (event.type == SDL_KEYUP) {
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                if(event.key.keysym.sym == SDLK_UP) {
                    if(indexActive == 2) indexActive = 1;
                    if(indexActive == 4) indexActive = 3;
                }
                if(event.key.keysym.sym == SDLK_RIGHT) {
                    if((indexActive == 3) || (indexActive == 4)) indexActive = 1;
                }
                if(event.key.keysym.sym == SDLK_DOWN) {
                    if(indexActive == 1) indexActive = 2;
                    if(indexActive == 3) indexActive = 4;
                }
                if(event.key.keysym.sym == SDLK_LEFT) {
                    if((indexActive == 1) || (indexActive == 2)) indexActive = 3;
                }
                if(event.key.keysym.sym == SDLK_RETURN) {
                    return indexActive;
                }
              }
        }
        
        //SDL_RenderCopy(renderer, imgBorder, NULL, &textRect);
       
        //SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        //SDL_RenderCopy(renderer, customize_imgBackground, NULL, &customize_backgroundRect);
        if (indexActive == 1) {
            color.g = 0;
            drawText(color, 1000, 500, "Eazy mode", renderer, font_Customize);
            color.g = 255;
            drawText(color, 200, 500, "Customize", renderer, font_Customize);
            drawText(color, 200, 1000, "Scoreboard", renderer, font_Customize);
            drawText(color, 1000, 600, "Hard mode", renderer, font_Customize);
        }
        else if(indexActive == 2) {
            color.g = 0;
            drawText(color, 1000, 600, "Hard mode", renderer, font_Customize);
            color.g = 255;
            drawText(color, 200, 500, "Customize", renderer, font_Customize);
            drawText(color, 200, 1000, "Scoreboard", renderer, font_Customize);
            drawText(color, 1000, 500, "Eazy mode", renderer, font_Customize);
        }
        else if(indexActive == 3) {
            color.g = 0;
            drawText(color, 200, 500, "Customize", renderer, font_Customize);
            color.g = 255;
            drawText(color, 1000, 600, "Hard mode", renderer, font_Customize);
            drawText(color, 200, 1000, "Scoreboard", renderer, font_Customize);
            drawText(color, 1000, 500, "Eazy mode", renderer, font_Customize);
        }
        else if(indexActive == 4) {
            color.g = 0;
            drawText(color, 200, 1000, "Scoreboard", renderer, font_Customize);
            color.g = 255;
            drawText(color, 1000, 600, "Hard mode", renderer, font_Customize);
            drawText(color, 200, 500, "Customize", renderer, font_Customize);
            drawText(color, 1000, 500, "Eazy mode", renderer, font_Customize);
        }
        //drawText(color, 150, 600, "char *text", renderer, font_options);
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(imgBackground);
    SDL_DestroyRenderer(renderer);
    //IMG_Quit();
    
    return 1;
}