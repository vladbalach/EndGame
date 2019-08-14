#include "header.h"

int scoreboard(SDL_Renderer *renderer) {
    bool running = true;
    SDL_Event event;
    int indexActive = 1;//1 - Ez,2-Hard,3-Cust,4-Score 
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    int page = 0; 
    TTF_Font *font = TTF_OpenFont("ttf/ofont.ru_Fixedsys.ttf",72);

    SDL_Color color = {255, 255, 0, 255};
    SDL_Color colorG = {0, 255, 0, 255};
    SDL_Color colorGR = {155, 255, 0, 255};
    //Customize panels


    //background 
    SDL_Rect backgroundRect = {0, 0, WIDTH_PIX, HEIGHT_PIX};
    SDL_Texture *imgBackground = IMG_LoadTexture(renderer, "sprites/blue.png");
    
    while(running) {
        int file = open("scoreboard/scoreboard.txt", O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IXUSR);
        int status = 1;
        int i = 0;
        int y = 6;
        int ch = 0;
        int yOnPage = 6;
         SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
        drawText(colorGR, 800, 100, "Scoreboard", renderer, font);
         drawText(colorGR, 100, 200, "Name", renderer, font);
        //drawText(color, 100, 200, "Name", renderer, font);
        drawText(color, 500, 200, "Games", renderer, font);
        drawText(color, 1000, 200, "Wins", renderer, font);
        while(status) {
            i = 0;
            //drawText(color, 100, 50*yOnPage, name, renderer, font);
            char *name = mx_strnew(100);
            char *games = mx_strnew(100);
            char *win = mx_strnew(100);
            while((status = read(file, &ch, 1)) && ch != ' ') {
                name[i] = ch;
                i++;
            }
            name[i] = 0;
                i = 0;
                    while(read(file, &ch, 1) && ch != ' ') {
                        games[i] = ch;
                        i++;
                    }
                    i=0;
                    while(read(file, &ch, 1) && ch != '\n') {
                        win[i] = ch;
                        i++;
                    }
                    if (((y-6) >= page * 14) && ((y-6) < (page+1) * 14)) {
                        drawText(colorGR, 100, 50*yOnPage, name, renderer, font);
                        drawText(color, 500, 50*yOnPage, games, renderer, font);
                        drawText(color, 1000, 50*yOnPage, win, renderer, font);
                        yOnPage++;
                    }
            free(name);
            free(games);
            free(win);
            y++;
        }
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if(event.key.keysym.sym == SDLK_RIGHT) {
                    page++;
                    printf("%d",page);
                }
                if(event.key.keysym.sym == SDLK_LEFT) {
                    if (page > 0) page -- ;
                }
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    return 6;
                }
              }
        }
        usleep(10000);
        SDL_RenderPresent(renderer);
        close(file);
    }
    SDL_DestroyTexture(imgBackground);

    
    return 1;
}