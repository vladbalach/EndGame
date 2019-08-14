#include "header.h"

void check_x(t_player *player, char* mass, int width) {
    int place = ((player->y * width) + player->x); //initializing in massive start position of player
    int i = 0;
    if (player->dx == 0) {
        player->dx = 0;
    }
    if (player->dx > 0) {
        while (mass[place + 1] != '0') {
            if ((player->dx == i) && (mass[place + 1] != '0')) {
                player->dx = i;
                return;
            }
            i++;
            place++;
        }
        player->dx = i - 1;
    }

    if (player->dx < 0) {
        while (mass[place - 1] != '0') {
            if (((player->dx) == -i) && (mass[place - 1] != '0')) {
                player->dx = -i;
                return;
            }
            i++;
            place--;
        }
        player->dx = -i + 1;
    }
}
