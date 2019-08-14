#include "header.h"

void drawMap( SDL_Renderer *render, char* MAP) {
    SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Texture *imgBorder = IMG_LoadTexture(render, "imgs/1.png");
    for (int i = 0; i < HEIGHT_SYMB; i++){
            for (int j = 0; j < WIDTH_SYMB; j++) {
                if (*(MAP + i * WIDTH_SYMB + j) == '0') {
                    rect.x = j * SIZE_OF_SYMBOL;
                    rect.y = i * SIZE_OF_SYMBOL;
                    SDL_RenderCopy(render, imgBorder, NULL, &rect);
                    //SDL_RenderFillRect(renderer, &rect);
                }
                else if (*(MAP + i * WIDTH_SYMB + j) == '1') {
                    rect.x = j * SIZE_OF_SYMBOL;
                    rect.y = i * SIZE_OF_SYMBOL;
                    SDL_RenderCopy(render, imgBorder, NULL, &rect);
                    //SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
}
