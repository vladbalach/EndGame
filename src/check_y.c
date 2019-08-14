#include "header.h"

void check_y(t_player *player, char* mass, int width) { 
    int place = ((player->y * width) + player->x);
    int i = 1;
    if (player->dy == 0)
        return;
    if (player->dy > 0) {
        while ((mass[place + width] != '0') && (mass[place + width] != '1')) {
            if (player->dy == i) {
                player->dy = i;
                return;
            }
            i++;
            place += width;
        }
        player->dy = i - 1;
    }
    if (player->dy < 0) {
        while ((mass[place - width] != '0') && (mass[place - width] != '1')) {
            if (player->dy == -i) {
                player->dy = -i;
                return;
            }
            i++;
            place -= width;
        }
        player->dy = -i + 1; 
    }
}
