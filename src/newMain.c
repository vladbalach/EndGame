#include "header.h"


/*void gameFunc() {
    player1, player2;
    int gameMod = 0;//1 - Отдых; 2 - Соревнование
    gameMod = showStartMenu();
    gameStart(int mode);//
    gameEnd()
}

void gameStart(int mode) {
    if(mode == 1) {
        startChill();
    }
    if(mode == 2) {
        startHard();
    }
}*/

int main() {
    int status = 1;//0 - exit; 1 - continue
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = 
    SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, WIDTH_PIX, HEIGHT_PIX, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    status = showStartMenu(renderer);
    t_player *player = 0;
    if (status == 4)
    mx_checkPlayers(/*t_player *player, t_player *player2,*/renderer);
    //SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);
    if (status == 2) {
        while(status) {
            status = startHard(player, renderer);
            if (status == 0) {
                break;
            }
            status = endScreen(player, renderer);
        }
    }
    if (status == 1) {
        //EzMode
    }
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}