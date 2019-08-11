#include "header.h"

int moveBullet(t_bullet **bullet, char *MAP) {
    if (*bullet == 0) return 0;
    t_bullet *tmp = *bullet;
    int oneDx = (tmp->dx > 0) ? 1 : ((tmp->dx == 0) ? 0 : -1);
    int oneDy = (tmp->dy > 0) ? 1 : ((tmp->dy == 0) ? 0 : -1);
    int index = 0;
    while (tmp) {
        
         //printf("y = %d\n", tmp->y);
        if ((*(MAP + WIDTH_SYMB * tmp->y + tmp->x) == '|') && (tmp->y < HEIGHT_SYMB-1))
                *(MAP + WIDTH_SYMB * tmp->y + tmp->x) = ' ';
        if ((tmp->y < 1) || (tmp->y > HEIGHT_SYMB - 2))
        {
            mx_pop_index(bullet, index);
            index--;
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
            if (tmp->y > 0)
            {
                
                if (*(MAP + WIDTH_SYMB * tmp->y + tmp->x) == 'A') {
                    return -1;//LOSE A
                } else
                if (*(MAP + WIDTH_SYMB * tmp->y + tmp->x) == 'B') {
                     return 1;//LOSE B
                }
                if (*(MAP + WIDTH_SYMB * tmp->y + tmp->x) != '1') {
                    *(MAP + WIDTH_SYMB * tmp->y + tmp->x) = '|';
                } 
            }
        }
        tmp = tmp->next;
        index++;
    }
    return 0;
    //free(tmp);
}