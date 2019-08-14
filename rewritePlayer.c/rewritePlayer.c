//#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdbool.h>
#include <time.h>
#include <fcntl.h>

#define SIZE_OF_SYMBOL 32
#define HEIGHT_SYMB 39 // MAP SYMBOLS
#define WIDTH_SYMB 60 
#define WIDTH_PIX (WIDTH_SYMB * SIZE_OF_SYMBOL)
#define HEIGHT_PIX (HEIGHT_SYMB * SIZE_OF_SYMBOL)

typedef struct s_player {
    float x;
    float y;
    float cloneX;
    float cloneY;
    float dx;
    float dy;
    float speed;
    char ch;
    char chClone;
    float bulletSpeed; // Скорость снаряда
    int coolDown; //gthезарядка
    int games;
    int win;
    char *name;
    char *pathToTexture;
    char *pathToBullet;
} t_player;
void initPlayers(t_player **player1, t_player **player2) {
    t_player *players1 = (t_player*) malloc(sizeof(t_player));
    t_player *players2 = (t_player*) malloc(sizeof(t_player));
    players1->x = WIDTH_SYMB / 4 - 1;
    players1->y =  HEIGHT_SYMB - 2;
    players1->cloneY = 1;
    players1->ch = 'A';
    players1->chClone = 'a';
    players1->pathToTexture = (char*) malloc (100);
    players1->pathToTexture = "sprites/playerShip2_red.png";
    players1->games = 215;
    players1->win = 0;
    players1->speed = 1;
    players2->bulletSpeed = players1->bulletSpeed = 0.35;
    players2->coolDown = players1->coolDown  = 180000;
    players2->ch = 'B';
    players2->chClone = 'b';
    players2->x = WIDTH_SYMB / 4 * 3 - 1 ;
    players2->y = HEIGHT_SYMB - 2; 
    players2->speed = 1;
    players2->cloneY = 1;
    players2->games = 0;
    players2->win = 0;
    players2->pathToTexture = (char*) malloc (100);
    players2->pathToTexture = "sprites/playerShip1_blue.png";
    players1->pathToBullet = "sprites/bull_red.png";
    players2->pathToBullet = "sprites/bull_blue2.png";
    players1->cloneX = players2->x + 1;
    players2->cloneX = players1->x + 1;
    players2->name = (char*) malloc (100);
    players1->name = (char*) malloc (100);
    players1->name = "Player1";
    players2->name = "Player2";
    *player1 = players1;
    *player2 = players2;
}

int mx_strcmp(const char *s1, const char *s2){
   while((*s1 || *s2)){
      if (*s1 != *s2)
            return *s1 - *s2;
         s1++;
         s2++;
     }
     return 0;
}
char *mx_strnew(const int size) {
    if (size > 0) {
        char *ptr = (char *) malloc (size + 1);
        if(ptr == 0) return 0;
        for (int i = 0; i < size; i++) {
            *(ptr + i) = '\0';
        }
        *(ptr + size) = '\0';
        return ptr;
    }
    else {
        return 0;
    }
}
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
int main() {
    t_player *player1;
    t_player *player2;
    initPlayers(&player1, &player2);
    rewritePlayer(&player1);
    rewritePlayer(&player2);
    //printf("%s",formatedInt(123));
}