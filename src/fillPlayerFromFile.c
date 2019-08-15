#include "header.h"

static void witePlayerToFile(t_player **player) {
    int file = open("scoreboard/scoreboard.txt", O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IXUSR);
    int i=0;
    while((*player)->name[i]) {
        write(file, &((*player)->name[i]), 1);
        i++;
    }
    write(file, " 00000 00000\n", 13);
    close(file);
}

void fillplayerFromFile(t_player **player1, t_player **player2) {
    int file = open("scoreboard/scoreboard.txt", O_RDWR,  S_IRUSR | S_IWUSR | S_IXUSR);
    if(file  < 0) return;
    int finded = 0;
    char ch = 0;
    int i=0;
    int status = 1;
    while(status) {
        
        char *name = mx_strnew(100);
        char *games = mx_strnew(100);
        char *win = mx_strnew(100);
        i=0;
            while((status = read(file, &ch, 1)) && ch != ' ') {
                name[i] = ch;
                i++;
            }
            name[i] = 0;
                i = 0;
                if ((mx_strcmp((*player1)->name, name) == 0) && (finded != 1)) {
                    finded += 1;
                    while(read(file, &ch, 1) && ch != ' ') {
                        games[i] = ch;
                        i++;
                    }
                    i=0;
                    (*player1)->games = atoi(games);
                    while(read(file, &ch, 1) && ch != '\n') {
                        win[i] = ch;
                        i++;
                    }
                    (*player1)->win = atoi(win);
                   
                }
                 
                else if ((mx_strcmp((*player2)->name, name) == 0) && (finded != 2)){
                    finded += 2;
                    while(read(file, &ch, 1) && ch != ' ') {
                        games[i] = ch;
                        i++;
                    }
                    i=0;
                    (*player2)->games = atoi(games);
                    while(read(file, &ch, 1) && ch != '\n') {
                        win[i] = ch;
                        i++;
                    }
                    (*player2)->win = atoi(win);
                }
                else while ((status = read(file, &ch, 1)) && ch != '\n') {}
            free(name);
            free(games);
            free(win); 
        }
        close(file);
        if(finded == 0) {
            witePlayerToFile(player1);
            witePlayerToFile(player2);
        }
        if(finded == 2) 
            witePlayerToFile(player1);
        if(finded == 1) 
            witePlayerToFile(player2);
    }
