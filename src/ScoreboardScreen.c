#include "header.h"

int scoreboard(SDL_Renderer *renderer) {
    bool running = true;
    SDL_Event event;
    int indexActive = 1;//1 - Ez,2-Hard,3-Cust,4-Score 
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    
    TTF_Font *font = TTF_OpenFont("ttf/ofont.ru_Fixedsys.ttf",72);

    SDL_Color color = {255, 255, 0, 255};
    //Customize panels


    //background 
    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/blue.png");
     int file = open("scoreboard/scoreboard.txt", O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IXUSR);
    while(running) {
        int status = 0;
        int i = 0;
        int y = 0;
        int ch = 0;
        while(status) {
        char *name = mx_strnew(100);
        char *games = mx_strnew(100);
        char *win = mx_strnew(100);
        
            while((status = read(file, &ch, 1)) && ch != ' ') {
                name[i] = ch;
                i++;
            }
            name[i] = 0;
            drawText(color, 100, 50*y, name, renderer, font);
                i = 0;
                    while(read(file, &ch, 1) && ch != ' ') {
                        games[i] = ch;
                        i++;
                    }
                    i=0;
                    drawText(color, 500, 50*y, games, renderer, font);
                    while(read(file, &ch, 1) && ch != '\n') {
                        win[i] = ch;
                        i++;
                    }
                    drawText(color, 1000, 50*y, win, renderer, font);
            free(name);
            free(games);
            free(win);
            y++;
        }
        color.r = 255;
        color.g = 255;
        color.b = 0;
        color.a = 255;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if(event.key.keysym.sym == SDLK_RIGHT) {
                    
                }
                if(event.key.keysym.sym == SDLK_LEFT) {
                    
                }
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    return 0;
                }
              }
        }
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(imgBackground);

    
    return 1;
}