#include "header.h"

void moveBullet(t_bullet **bullet, char *MAP) {
    if (*bullet == 0) return;
    t_bullet *tmp = *bullet;
    int oneDx = (tmp->dx > 0) ? 1 : ((tmp->dx == 0) ? 0 : -1);
    int oneDy = (tmp->dy > 0) ? 1 : ((tmp->dy == 0) ? 0 : -1);
    int index = 0;
    while (tmp) {
         //printf("y = %d\n", tmp->y);
        if (*(MAP + WIDTH_SYMB * tmp->y + tmp->x) == '|')
                *(MAP + WIDTH_SYMB * tmp->y + tmp->x) = ' ';
        if ((tmp->y < 2) || (tmp->y > HEIGHT_SYMB - 2))
        {
            mx_pop_index(bullet, index);
        }
        else
        {
            for (int i = 0; i < tmp->dx; i++) {
                if (*(MAP + WIDTH_SYMB * tmp->y + tmp->x) == '0') {
                    oneDx = -oneDx;
                }
                tmp->x = oneDx;
            }
            tmp->y += tmp->dy;
            if (*(MAP + WIDTH_SYMB * tmp->y + tmp->x) != '1') {
               *(MAP + WIDTH_SYMB * tmp->y + tmp->x) = '|';
            } 
        }
        tmp = tmp->next;
        index++;
    }
    //free(tmp);
}