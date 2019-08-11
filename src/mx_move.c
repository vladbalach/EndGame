#include "header.h"

void mx_move(t_player* player, char *MAP) {
    //*(MAP + WIDTH_SYMB * 2 + player->x) = '0';
    //  *(MAP + WIDTH_SYMB * player->y + player->x-1) = ' ';
    //  *(MAP + WIDTH_SYMB * player->y + player->x+1) = ' ';
    //  *(MAP + WIDTH_SYMB * player->cloneY + player->cloneX) = ' ';
    //  *(MAP + WIDTH_SYMB * player->cloneY + player->cloneX + 1) = ' ';
    //  *(MAP + WIDTH_SYMB * player->cloneY + player->cloneX - 1) = ' ';
    player->x = player->x + player->dx;
    player->y = player->y - player->dy;
    player->cloneX = player->cloneX - player->dx;
    player->cloneY = player->cloneY + player->dy;
    //*(MAP + WIDTH_SYMB * player->y + player->x) = player->ch;
    // *(MAP + WIDTH_SYMB * player->y + player->x-1) = player->ch;
    // *(MAP + WIDTH_SYMB * player->y + player->x+1) = player->ch;
    // *(MAP + WIDTH_SYMB * player->cloneY + player->cloneX) = player->chClone;
    // *(MAP + WIDTH_SYMB * player->cloneY + player->cloneX + 1) = player->chClone;
    // *(MAP + WIDTH_SYMB * player->cloneY + player->cloneX - 1) = player->chClone;
}
