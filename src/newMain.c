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
        showStartMenu();
    while(status) {
        status = startHard();
        if (status == 0) {
            break;
        }
        endScreen();
    }
    return 0;
}