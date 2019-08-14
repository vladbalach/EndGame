#include "header.h"

void mx_pop_index(t_bullet **list, int index) {
    if (index <= 0) {
        mx_pop_front(list);
    }
    else {
        t_bullet *l = *list;
        for (int i = 0; i < index-1; i++) {
            if (l->next->next == 0) break;
            l = l->next;
        }
        if (l->next->next == 0) {
            mx_pop_back(list);
            
        } 
        else {
            t_bullet *tmp = l->next->next;
            free(l->next);
            l->next = tmp;
        }
    }
}
