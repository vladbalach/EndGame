#include "header.h"

void drawText(SDL_Color color, int x, int y, char *text, SDL_Renderer *renderer,  int size) {
    TTF_Font *font = TTF_OpenFont("ttf/OpenSansBold.ttf", size);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *textureGameName = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {x,y,1,1};
    SDL_QueryTexture(textureGameName, NULL, NULL, &textRect.w, &textRect.h);
    SDL_RenderCopy(renderer, textureGameName, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    textSurface = 0;
    free(font);
    font = 0;
    SDL_DestroyTexture(textureGameName);
}
