#include "header.h"

t_bullet *createBullet(float x, float y, float dx, float dy, char ch, char *MAP) {
    t_bullet *bullet = (t_bullet*) malloc (sizeof(t_bullet));
    bullet->dx = dx;
    bullet->dy = dy;
    bullet->x = x;
    bullet->y = y;
    bullet->ch = ch;
    bullet->next = 0;
    if (*(MAP + WIDTH_SYMB * (int)bullet->y + (int)bullet->x) == ' ') {
        *(MAP + WIDTH_SYMB * (int)bullet->y + (int)bullet->x) = ch;
    }
    return bullet;
}
