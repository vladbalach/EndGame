#include "header.h"

char *mx_strnew(const int size) {
    if (size > 0) {
        char *ptr = (char *) malloc (size + 1);
        if(ptr == 0) return 0;
        for (int i = 0; i < size; i++) {
            *(ptr + i) = '\0';
        }
        *(ptr + size) = '\0';
        return ptr;
    }
    else {
        return 0;
    }
}
