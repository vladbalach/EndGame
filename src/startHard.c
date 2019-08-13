#include "header.h"

static void initPlayers(t_player *player1, t_player *player2) {
    player1->x = WIDTH_SYMB / 4 - 1;
    player1->y =  HEIGHT_SYMB - 2;
    player1->cloneY = 1;
    player1->ch = 'A';
    player1->chClone = 'a';
    player1->pathToTexture = (char*) malloc (100);
    player1->pathToTexture = "sprites/playerShip2_red.png";
    player1->speed = 1;
    player2->bulletSpeed = player1->bulletSpeed = 0.35;
    player2->coolDown = player1->coolDown  = 180000;
    player2->ch = 'B';
    player2->chClone = 'b';
    player2->x = WIDTH_SYMB / 4 * 3 - 1 ;
    player2->y = HEIGHT_SYMB - 2; 
    player2->speed = 1;
    player2->cloneY = 1;
    player2->pathToTexture = (char*) malloc (100);
    player2->pathToTexture = "sprites/playerShip1_blue.png";
    player1->cloneX = player2->x + 1;
    player2->cloneX = player1->x + 1;
}

int startHard() {
    char MAP[HEIGHT_SYMB][WIDTH_SYMB];
    t_player player1;
    t_player player2;
    initPlayers(&player1, &player2);
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
    SDL_Texture *imgB = IMG_LoadTexture(renderer, "sprites/black.png");
    bool running = true;
    SDL_Event event;
    SDL_Rect rectPlayer1 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rectPlayer2 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    initMap(&MAP[0][0]);
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, "sprites/crate_01.png");
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    ///TTF

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
            running = false;
        }
        if(GAME_STATUS == 1) {
            printf("Second lose");
            running = false;
        }
        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_Rect rect3 = {0, 0, WIDTH_SYMB * SIZE_OF_SYMBOL, HEIGHT_SYMB * SIZE_OF_SYMBOL};
        SDL_RenderCopy(renderer, imgB, NULL, &rect3);
        // ОБРАБОТКА СИМВОЛОВ 
        // ТУТ ТРЕТИЙ ТАСК
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
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
                    return 0;
                }
            }
            if(event.type == SDL_QUIT) {
                return 0;
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
    //SDL_DestroyTexture(textTexture);
   // SDL_FreeSurface(textSurface);
    clearBulletList(&listBullet, &MAP[0][0]);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    //IMG_Quit();
    SDL_Quit();
    return 1;
}