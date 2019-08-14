#include "header.h"

void mx_push_front(t_bullet **list, float x, float y, float dx,float dy, char ch,  char *MAP) {
    t_bullet *head = createBullet(x, y, dx, dy, ch, MAP);
    head->next = *list;
    *list = head;
}
