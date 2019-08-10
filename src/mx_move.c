#include "header.h"

void mx_move(t_player* player) {
    player->x = player->x - player->dx;
    player->y = player->y - player->dy;
    player->cloneX = player->cloneX + player->dx;
    player->cloneY = player->cloneY + player->dy;
}
