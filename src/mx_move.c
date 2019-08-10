#include "header.h"

void mx_move(*t_player player){
    player->x = player->x - dx;
    player->y = player->y - dy;
    player->cloneX = player->cloneX + dx;
    player->cloneY = player->cloneY + dy;
}