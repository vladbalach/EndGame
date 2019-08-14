#include "header.h"

static int lengthOfint(int num) {
    int i = 0;
    while(num > 0) {
        num /= 10;
        i++;
    }
    return i;
}

static char* formatedInt(int num) {
    int len = lengthOfint(num);
    char *str =(char *) malloc (6);
    for (int i = 4;i>=0;i--) {
            str[i] = num % 10 + 48;
            num/=10;
    }
    str[5] = 0;
    return str;
}

void rewritePlayer(t_player **player) {
    int file = open("../scoreboard/scoreboard.txt", O_RDWR,  S_IRUSR | S_IWUSR | S_IXUSR);
    if(file  < 0) 
    {
         printf("CantOpen!");
        return;
    }
    int finded = 0;
    char ch = 0;
    int i=0;
    int status = 1;
    while(status) {
        i=0;
            char *name = mx_strnew(100);
            while((status = read(file, &ch, 1)) && ch != ' ') {
                name[i] = ch;
                i++;
            }
            name[i] = 0;
            if ((mx_strcmp((*player)->name, name) == 0) && (finded != 1)) {
                finded += 1;
                char *win = formatedInt((*player)->win);
                char *games = formatedInt((*player)->games);
                write(file, games,5);
                write(file, " ", 1);
                write(file, win,5);
                write(file, "\n", 1);
            }
            else while ((status = read(file, &ch, 1)) && ch != '\n') {}
            free(name);
        }
        close(file);
}
