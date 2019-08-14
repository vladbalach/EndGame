#include "header.h"

void initMap(char *mass) {
    for (int i = 0; i < HEIGHT_SYMB; i++) {
        for (int j = 0; j < WIDTH_SYMB; j++) {
            if ((i == 0) || (j == 0) 
            || (i == HEIGHT_SYMB - 1) || (j == WIDTH_SYMB - 1)
            || (j == WIDTH_SYMB / 2) || (j == WIDTH_SYMB / 2 - 1))
                *(mass + WIDTH_SYMB * i + j) = '0';
            else if (i == HEIGHT_SYMB / 2)
                *(mass + WIDTH_SYMB * i + j) = '1';
            else {
                *(mass + WIDTH_SYMB * i + j) = ' ';
            }
        }
    }
}
