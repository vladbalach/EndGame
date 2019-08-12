#include "header.h"


// Draw points with random colors and positions
// HEIGHT_SYMB - максимальная высота масива
// WIDTH_SYMB - максимальная ширина масива
// Сюда добавить единицы и нули
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
void rm(t_bullet **list) {
    free(*list);
}
int main(int argc, char **argv)
{
    //(SPI_SETKEYBOARDDELAY, 0, 0, 0)
    //const Uint8 *state = SDL_GetKeyboardState(NULL);
    char MAP[HEIGHT_SYMB][WIDTH_SYMB];
    t_player player1;
    player1.x = WIDTH_SYMB/4 - 1;
    player1.y =  HEIGHT_SYMB - 2;
    player1.cloneY = 1;
    player1.bulletSpeed = 0.35;
    player1.ch = 'A';
    player1.chClone = 'a';
    player1.coolDown = 500000; 
    player1.pathToTexture = (char*) malloc (100);
    player1.pathToTexture = "sprites/spaceStation_023.png";
    player1.speed = 1;
    t_player player2;
    player2.bulletSpeed = 0.35;
    player2.coolDown = 500000;
    player2.ch = 'B';
    player2.chClone = 'b';
    player2.x = WIDTH_SYMB / 4 * 3 - 1 ;
    player2.y = HEIGHT_SYMB - 2; 
    player2.speed = 1;
    player2.cloneY = 1;
    player2.pathToTexture = (char*) malloc (100);
    player2.pathToTexture = "sprites/spaceStation_018.png";
    player1.cloneX = player2.x+1;
    player2.cloneX = player1.x+1;
    clock_t startTime, cd1, cd2;
    startTime = clock();
    cd1 = clock();
    cd2 = clock();
    //timerTo
    int GAME_STATUS = 0;//
    t_bullet *listBullet = 0;
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
   //SDL_Texture *imgBorder = IMG_LoadTexture(renderer, "imgs/1.png");
    //SDL_Texture *imgBorder2 = IMG_LoadTexture(renderer, "sprites/environment_02.png");
    // Create a SDL window
    SDL_Window *window = 
    SDL_CreateWindow("Hello, SDL2", 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, WIDTH_PIX, HEIGHT_PIX, 
    SDL_WINDOW_OPENGL);
    //SDL_SetWindowFullscreen (window,/*SDL_WINDOW_FULLSCREEN*/SDL_WINDOW_FULLSCREEN_DESKTOP);
    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *imgB = IMG_LoadTexture(renderer, "imgs/zori.png");
    bool running = true;
    SDL_Event event;
    SDL_Rect rectPlayer1 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rectPlayer2 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    initMap(&MAP[0][0]);
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, "sprites/crate_01.png");
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    //                free(imgBorder);
    //drawMap(&rect, renderer, &MAP[0][0]);
    //t_bullet *t1 = createBullet(1,1,1,1,&MAP[0][0]);
  
    ////t_bullet *t2 = createBullet(1,1,1,1,&MAP[0][0]);
    //t1->next = t2;
    //rm(&t1);
   // mx_push_front(&listBullet, 3, 4, 0, 1, &MAP[0][0]);
   // mx_push_front(&listBullet, 3, 6, 0, 1, &MAP[0][0]);
   // mx_push_front(&listBullet, 3, 8, 0, 1, &MAP[0][0]);
    //mx_push_front(&listBullet, 3, 10, 0, 1, &MAP[0][0]);
    //t_bullet *t = listBullet->next;
    //listBullet->next = listBullet->next->next;
    //free(t);
    //printf("x=%f y=%f", listBullet->next->x, listBullet->next->next->y);
    //free(listBullet);
    /////////////////
    
    while(running)
    {
        //printf("time = %lu\n",cd1);
       // state = SDL_GetKeyboardState(NULL);
        player1.dx = 0;
        player1.dy = 0;
        player2.dx = 0;
        player2.dy = 0;
        GAME_STATUS = moveBullet(&listBullet,&MAP[0][0]);
        if(GAME_STATUS == -1) {
            printf("First lose");
            exit(1);

        }
        if(GAME_STATUS == 1) {
            printf("Second lose");
            exit(1);
            
        }
        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_Rect rect3 = {0, 0, WIDTH_SYMB * SIZE_OF_SYMBOL, HEIGHT_SYMB * SIZE_OF_SYMBOL};
        SDL_RenderCopy(renderer, imgB, NULL, &rect3);
        // ОБРАБОТКА СИМВОЛОВ 
        // ТУТ ТРЕТИЙ ТАСК
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if((event.key.keysym.sym == SDLK_SPACE) && (clock() > cd1 + player1.coolDown + 500000)) {

                }
                if((event.key.keysym.sym == SDLK_SPACE) && (clock() > cd1 + player1.coolDown)) {
                    cd1 = clock();
                    mx_push_front(&listBullet, player1.x, player1.y - 1, 0, -player1.bulletSpeed, &MAP[0][0]);
                    mx_push_front(&listBullet, player1.cloneX, player1.cloneY + 1, 0, player1.bulletSpeed, &MAP[0][0]);
                    break;
                }
                
                if((event.key.keysym.sym == SDLK_RSHIFT)&& (clock() > cd2 + player2.coolDown)) {
                    cd2 = clock();
                    mx_push_front(&listBullet, player2.x, player2.y - 1, 0, -player2.bulletSpeed, &MAP[0][0]);
                    mx_push_front(&listBullet, player2.cloneX, player2.cloneY + 1, 0, player2.bulletSpeed, &MAP[0][0]);
                    break;
                }
                if(event.key.keysym.sym == SDLK_w) {
                    player1.dy = -player1.speed;
                    //clearBulletList(&listBullet, &MAP[0][0]);
                    //rm(&listBullet);
                }
                if(event.key.keysym.sym == SDLK_a) {
                    player1.dx = -player1.speed;
                }
                if(event.key.keysym.sym == SDLK_s) {
                    player1.dy = player1.speed;
                }
                if(event.key.keysym.sym == SDLK_d) {
                    player1.dx = player1.speed;
                }
                if(event.key.keysym.sym == SDLK_UP) {
                    player2.dy = -player2.speed;
                }
                if(event.key.keysym.sym == SDLK_RIGHT) {
                    player2.dx = player2.speed;
                }
                if(event.key.keysym.sym == SDLK_DOWN) {
                    player2.dy = player2.speed;
                }
                if(event.key.keysym.sym == SDLK_LEFT) {
                    player2.dx = -player2.speed;
                }
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
            if(event.type == SDL_QUIT) {
                
                running = false;
            }
        } 
        checkMove(&player1, &MAP[0][0], WIDTH_SYMB);
        checkMove(&player2, &MAP[0][0], WIDTH_SYMB);
        mx_move(&player1, &MAP[0][0]);
        mx_move(&player2, &MAP[0][0]);
        drawPlayer(&player1, renderer);
        drawPlayer(&player2, renderer);
        redrawMap(renderer, &MAP[0][0]);
        usleep(1000);
        SDL_RenderPresent(renderer);
    }
    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
