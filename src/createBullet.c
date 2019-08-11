#include "header.h"

t_bullet *createBullet(float x, float y, float dx, float dy, char *MAP) {
    t_bullet *bullet = (t_bullet*) malloc (sizeof(t_bullet));
    bullet->dx = dx;
    bullet->dy = dy;
    bullet->x = x;
    bullet->y = y;
    bullet->next = 0;
    *(MAP + WIDTH_SYMB * (int)bullet->y + (int)bullet->x) = '|';
    return bullet;
}
