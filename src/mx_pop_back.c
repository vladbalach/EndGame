#include "header.h"

void mx_pop_back(t_bullet **list) {
    if (*list == 0) {
        return;
    }
    else {
        t_bullet *l = *list;
        while(l->next->next != 0) {
            l = l->next;
        }
        free(l->next);
        l->next = 0;
    }
}
