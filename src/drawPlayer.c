#include "header.h"

void drawPlayer(t_player *player, SDL_Renderer *render) {
    //
    SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Texture *imgBorder = IMG_LoadTexture(render, player->pathToTexture);
    rect.x = (player->x - 1)* SIZE_OF_SYMBOL;
    rect.y = player->y * SIZE_OF_SYMBOL;
    rect.w = SIZE_OF_SYMBOL * 3;
    
    SDL_RenderCopy(render, imgBorder, NULL, &rect);
    
    SDL_Rect rect2 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Texture *imgBorder2 = IMG_LoadTexture(render, player->pathToTexture);
    rect2.x = (player->cloneX - 1) * SIZE_OF_SYMBOL;
    rect2.y = player->cloneY * SIZE_OF_SYMBOL;
    rect2.w = SIZE_OF_SYMBOL * 3;
    
    SDL_RenderCopy(render, imgBorder2, NULL, &rect2);//SDL_RenderFillRect(render, rect);
    //free(&rect);
    //free(&rect2);
    //free(imgBorder);
    //free(imgBorder2);
    SDL_DestroyTexture(imgBorder);
    SDL_DestroyTexture(imgBorder2);
}
