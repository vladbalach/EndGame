#include "header.h"
void clearBulletList(t_bullet **list, char* MAP) {
    t_bullet *tmp = *list;
    if(*list == 0) return;
    while(tmp)
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
    //(*list)->dy = 100;
    //free(*list);
    //free(list);
    //tmp = NULL;
    //tmp = *list;
    //if(*(MAP + WIDTH_SYMB * (int)tmp->y  + (int)tmp->x) == '|') {
    //        *(MAP + WIDTH_SYMB * (int)tmp->y  + (int)tmp->x) = ' ';
    //    }
    //tmp->next = 0;
    //free(*list);
}
