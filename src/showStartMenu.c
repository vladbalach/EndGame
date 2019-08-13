#include "header.h"




int showStartMenu(SDL_Renderer *renderer, t_player *player1, t_player *player2) {
    bool running = true;
    SDL_Event event;
    int indexActive = 1;//1 - Ez,2-Hard,3-Cust,4-Score 
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    
    TTF_Font *font_Customize = TTF_OpenFont("ttf/ofont.ru_Fixedsys.ttf",72);
    /*if (font_GameName == 0) {
          printf("%s",TTF_GetError());
          exit(1);
    };*/

    SDL_Color color = {255, 255, 0, 255};
    //Customize panels
    SDL_Rect button1 = {715, 435, 400, 120};
    SDL_Texture *button11 = IMG_LoadTexture(renderer, "sprites/button.png");
    SDL_Rect button2 = {715, 585, 400, 120};
    SDL_Texture *button22 = IMG_LoadTexture(renderer, "sprites/button.png");
    SDL_Rect button3 = {280, 935, 400, 120};
    SDL_Texture *button33 = IMG_LoadTexture(renderer, "sprites/button.png");
    SDL_Rect button4 = {1160, 935, 400, 120};
    SDL_Texture *button44 = IMG_LoadTexture(renderer, "sprites/button.png");

    //background 
    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/main_menu_background.png");

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
                    if(indexActive == 4) indexActive = 2;
                    if(indexActive == 3) indexActive = 2;
                }
                if(event.key.keysym.sym == SDLK_RIGHT) {
                    if(indexActive == 4) indexActive = 3;
                }
                if(event.key.keysym.sym == SDLK_DOWN) {
                    if(indexActive == 2) indexActive = 4;
                    if(indexActive == 1) indexActive = 2;
                }
                if(event.key.keysym.sym == SDLK_LEFT) {
                    if(indexActive == 3) indexActive = 4;
                }
                if(event.key.keysym.sym == SDLK_RETURN) {
                    return indexActive;
                }
              }
        }
        
        //SDL_RenderCopy(renderer, imgBorder, NULL, &textRect);
       
        //SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        SDL_RenderCopy(renderer, button11, NULL, &button1);
        SDL_RenderCopy(renderer, button22, NULL, &button2);
        SDL_RenderCopy(renderer, button33, NULL, &button3);
        SDL_RenderCopy(renderer, button44, NULL, &button4);
        //SDL_RenderCopy(renderer, customize_imgBackground, NULL, &customize_backgroundRect);
        if (indexActive == 1) {
            color.g = 0;
            drawText(color, 750, 450, "Easy mode", renderer, font_Customize);
            color.g = 255;
            drawText(color, 1200, 950, "Customize", renderer, font_Customize);
            drawText(color, 300, 950, "Scoreboard", renderer, font_Customize);
            drawText(color, 750, 600, "Hard mode", renderer, font_Customize);
        }
        else if(indexActive == 2) {
            color.g = 0;
            drawText(color, 750, 600, "Hard mode", renderer, font_Customize);
            color.g = 255;
            drawText(color, 1200, 950, "Customize", renderer, font_Customize);
            drawText(color, 300, 950, "Scoreboard", renderer, font_Customize);
            drawText(color, 750, 450, "Easy mode", renderer, font_Customize);
        }
        else if(indexActive == 3) {
            color.g = 0;
            drawText(color, 1200, 950, "Customize", renderer, font_Customize);
            color.g = 255;
            drawText(color, 750, 600, "Hard mode", renderer, font_Customize);
            drawText(color, 300, 950, "Scoreboard", renderer, font_Customize);
            drawText(color, 750, 450, "Easy mode", renderer, font_Customize);
        }
        else if(indexActive == 4) {
            color.g = 0;
            drawText(color, 300, 950, "Scoreboard", renderer, font_Customize);
            color.g = 255;
            drawText(color, 750, 600, "Hard mode", renderer, font_Customize);
            drawText(color, 1200, 950, "Customize", renderer, font_Customize);
            drawText(color, 750, 450, "Easy mode", renderer, font_Customize);
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