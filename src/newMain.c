#include "header.h"

int main() {
    int status = 4;//0 - exit; 1 - continue
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = 
    SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, WIDTH_PIX, HEIGHT_PIX, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    t_player *player1 = 0;
    t_player *player2 = 0;
    t_player *winPlayer = 0;
    initPlayers(&player1, &player2);
    while (status != 0) {
        status = showStartMenu(renderer, player1, player2);
        if (status == 3)
    status = mx_checkPlayers(&player1, &player2, renderer);
        if(status == 4) {
            scoreboard(renderer);
        }
    }
   if (status == 3)
    status = mx_checkPlayers(&player1, &player2, renderer);
    if(status == 4) {
       scoreboard(renderer);
    }
    if (status == 2) {
        while(status) {
            status = startHard(&player1, &player2, winPlayer, renderer);
            if (status == 0) {
                break;
            }
            if (status == 1){
                if (player2->health == 0) {
                    status = endScreen(player1, renderer);
                    player1->health = 3;
                    player2->health = 3;
                }
                else 
                    status = startHard(&player1, &player2, winPlayer, renderer);
            }
            if (status == 2) {
                if (player1->health == 0) {
                    status = endScreen(player1, renderer);
                    player1->health = 3;
                    player2->health = 3;
                }
                else 
                    status = startHard(&player1, &player2, winPlayer, renderer);
            }
        }
    }
    if (status == 1) {
        while(status) {
            status = startEasy(&player1, &player2, winPlayer, renderer);
            if (status == 0) {
                break;
            }
            if (status == 1){
                if (player2->health == 0) {
                    status = endScreen(player1, renderer);
                    player1->health = 3;
                    player2->health = 3;
                }
                else 
                    status = startEasy(&player1, &player2, winPlayer, renderer);
            }
            if (status == 2) {
                if (player1->health == 0) {
                    status = endScreen(player1, renderer);
                    player1->health = 3;
                    player2->health = 3;
                }
                else 
                    status = startEasy(&player1, &player2, winPlayer, renderer);
            }
        }
    }
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}