#include "header.h"
void clearBulletList(t_bullet **list, char* MAP) {
    t_bullet *tmp = *list;
    if(*list == 0) return;
    while(tmp->next)
    {
        while(tmp->next->next) {
        tmp = tmp->next;
        }
        if(*(MAP + WIDTH_SYMB * (int)tmp->next->y  + (int)tmp->next->x) == '|') {
            *(MAP + WIDTH_SYMB * (int)tmp->next->y  + (int)tmp->next->x) = ' ';
        }
        free(tmp->next);
        tmp->next=0;
        tmp = *list;
    }

}
