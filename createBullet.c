#include "header.h"

t_bullet *createBullet(int x, int y, int dx, int dy, char *MAP) {
    t_bullet *bullet = (t_bullet*) malloc (sizeof(t_bullet));
    bullet->dx = dx;
    bullet->dy = dy;
    bullet->x = x;
    bullet->y = y;
    bullet->next = 0;
    *(MAP + WIDTH_SYMB * bullet->y + bullet->x) = '|';
    return bullet;
}
