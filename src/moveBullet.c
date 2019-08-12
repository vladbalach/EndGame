#include "header.h"

int moveBullet(t_bullet **bullet, char *MAP) {
    if (*bullet == 0) return 0;
    t_bullet *tmp = *bullet;
    float oneDx = ((int)tmp->dx > 0) ? 1 : (((int)tmp->dx == 0) ? 0 : -1);
    float oneDy = ((int)tmp->dy > 0) ? 1 : (((int)tmp->dy == 0) ? 0 : -1);
    int index = 0;
    while (tmp) {
        if (*(MAP + WIDTH_SYMB * (int)tmp->y  + (int)tmp->x + (int)oneDx) == '0') {
                    oneDx = -oneDx;
                    tmp->dx = -tmp->dx;
        }
         //printf("y = %d\n", tmp->y) ;
        if ((*(MAP + WIDTH_SYMB * (int)tmp->y + (int)tmp->x) == '|') && ((int)tmp->y < HEIGHT_SYMB-1))
                *(MAP + WIDTH_SYMB * (int)tmp->y + (int)tmp->x) = ' ';
        if (((int)tmp->y < 1) || ((int)tmp->y > HEIGHT_SYMB - 3))
        {
            mx_pop_index(bullet, index);
            index--;
        }
        else
        {
            //for (int i = 0; i < tmp->dx; i++) {
                
                
            //}
            tmp->x += oneDx;
            tmp->y += tmp->dy;
            if ((int)tmp->y > 0)
            {
                
                if (*(MAP + WIDTH_SYMB * (int)tmp->y + (int)tmp->x) == 'A') {
                    return -1;//LOSE A
                } else
                if (*(MAP + WIDTH_SYMB * (int)tmp->y + (int)tmp->x) == 'B') {
                     return 1;//LOSE B
                }
                if (*(MAP + WIDTH_SYMB * (int)tmp->y + (int)tmp->x) != '1') {
                    *(MAP + WIDTH_SYMB * (int)tmp->y + (int)tmp->x) = '|';
                } 
            }
        }
        tmp = tmp->next;
        index++;
    }
    return 0;
    //free(tmp);
}