#include "header.h"

void redrawMap(SDL_Renderer *render, t_player *player1, t_player *player2, char* MAP) {
     SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Texture *imgBorder = IMG_LoadTexture(render, "sprites/transparent-square-tiles.png");
    SDL_Texture *redBullet = IMG_LoadTexture(render, player1->pathToBullet);
    SDL_Texture *blueBullet = IMG_LoadTexture(render, player2->pathToBullet);
    for (int i = 0; i < HEIGHT_SYMB; i++){
            for (int j = 0; j < WIDTH_SYMB; j++) {
                
                //printf("%c", *(MAP + i * WIDTH_SYMB + j));
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
                else if (*(MAP + i * WIDTH_SYMB + j) == '-') {
                    rect.x = j * SIZE_OF_SYMBOL;
                    rect.y = i * SIZE_OF_SYMBOL;
                    SDL_RenderCopy(render, redBullet, NULL, &rect);
                    //SDL_RenderFillRect(renderer, &rect);
                }
                else if (*(MAP + i * WIDTH_SYMB + j) == '+') {
                    rect.x = j * SIZE_OF_SYMBOL;
                    rect.y = i * SIZE_OF_SYMBOL;
                    SDL_RenderCopy(render, blueBullet, NULL, &rect);
                    //SDL_RenderFillRect(renderer, &rect);
                }
            }
            //printf("\n");
        }
        SDL_DestroyTexture(imgBorder);
        SDL_DestroyTexture(redBullet);
        SDL_DestroyTexture(blueBullet);
        //SDL_DestroyRect(&rect);
}
