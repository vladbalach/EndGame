#include "header.h"

void mx_pop_front(t_bullet **list) {
    if (*list == 0) {
        return;
    }
    else {
        t_bullet *l = (*list)->next;
        free(*list);
        (*list) = l;
    }
}
