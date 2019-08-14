#include "header.h"
static float randomize(float numb) {
    srand(time(0));
    float plus = rand() % 300;
    numb += numb * (plus / (float)100);
    
    return numb;
}
//"player" to out winner
int startHard(t_player *player11, t_player *player21, t_player *winPlayer, SDL_Renderer *renderer) {
    char MAP[HEIGHT_SYMB][WIDTH_SYMB];
    clock_t startTime, cd1, cd2;
    startTime = clock();
    cd1 = clock();
    cd2 = clock();
    t_player *player1 = 0; 
    t_player *player2 = 0;
    initPlayers(&player1, &player2);
    //timerTo
    int GAME_STATUS = 0;//
    t_bullet *listBullet = 0;
    // Initialize SDL
    float speedForIteration1 = player1->bulletSpeed;
    float speedForIteration2 = player2->bulletSpeed;
    //Creating MUSIC channel and adding tracks
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk *laser1 = Mix_LoadWAV("music/laser5.wav");
    Mix_Chunk *laser2 = Mix_LoadWAV("music/laser2.wav");
    Mix_Music *backgroundHard = Mix_LoadMUS("music/Orbital Colossus.mp3");

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Texture *imgB = IMG_LoadTexture(renderer, "sprites/newback1.png");
    bool running = true;
    Mix_PlayMusic(backgroundHard, -1);
    Mix_VolumeMusic(24);
    SDL_Event event;
    SDL_Rect rectPlayer1 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rectPlayer2 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    initMap(&MAP[0][0]);
    SDL_Texture *imgBorder = IMG_LoadTexture(renderer, "sprites/transparent-square-tiles.png");
    SDL_RenderCopy(renderer, imgBorder, NULL, &rect);
    ///TTF

    while(running)
    {
        
        speedForIteration1 = player1->bulletSpeed;
        speedForIteration2 = player2->bulletSpeed;
        if(startTime > 200000) {
            speedForIteration1 = randomize(player1->bulletSpeed);
            speedForIteration2 = randomize(player2->bulletSpeed);
            printf("%10.3f\n", speedForIteration1);
        }
        //printf("First lose");
        player1->dx = 0;
        player1->dy = 0;
        player2->dx = 0;
        player2->dy = 0;
        GAME_STATUS = moveBullet(&listBullet,&MAP[0][0]);
        if(GAME_STATUS == -1) {
            printf("First lose");
            //winPlayer = player2;
            return 1;
        }
        if(GAME_STATUS == 1) {
            printf("Second lose");
            //winPlayer = player1;
            return 2;
        }

        SDL_RenderClear(renderer);
        SDL_Rect rect3 = {0, 0, WIDTH_SYMB * SIZE_OF_SYMBOL, HEIGHT_SYMB * SIZE_OF_SYMBOL};
        SDL_RenderCopy(renderer, imgB, NULL, &rect3);

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                
                if((event.key.keysym.sym == SDLK_SPACE) && (clock() > cd1 + player1->coolDown)) {
                    cd1 = clock();
                    //CLOCKS_PER_SEC
                    Mix_PlayChannel(-1,laser1, 0);
                    Mix_Volume(-1, MIX_MAX_VOLUME);
                    
                    mx_push_front(&listBullet, player1->x, player1->y - 1, 0, -speedForIteration1, '-', &MAP[0][0]);
                    mx_push_front(&listBullet, player1->cloneX, player1->cloneY + 1, 0, speedForIteration1, '-', &MAP[0][0]);
                    break;
                }
                
                if((event.key.keysym.sym == SDLK_RSHIFT)&& (clock() > cd2 + player2->coolDown)) {
                    cd2 = clock();
                    Mix_PlayChannel(-1,laser1, 0);
                    Mix_Volume(-1, MIX_MAX_VOLUME);
                    mx_push_front(&listBullet, player2->x, player2->y - 1, 0, -speedForIteration2, '+', &MAP[0][0]);
                    mx_push_front(&listBullet, player2->cloneX, player2->cloneY + 1, 0, speedForIteration2, '+', &MAP[0][0]);
                    break;
                }
                if(event.key.keysym.sym == SDLK_w) {
                    player1->dy = -player1->speed;
                }
                if(event.key.keysym.sym == SDLK_a) {
                    player1->dx = -player1->speed;
                }
                if(event.key.keysym.sym == SDLK_s) {
                    player1->dy = player1->speed;
                }
                if(event.key.keysym.sym == SDLK_d) {
                    player1->dx = player1->speed;
                }
                if(event.key.keysym.sym == SDLK_UP) {
                    player2->dy = -player2->speed;
                }
                if(event.key.keysym.sym == SDLK_RIGHT) {
                    player2->dx = player2->speed;
                }
                if(event.key.keysym.sym == SDLK_DOWN) {
                    player2->dy = player2->speed;
                }
                if(event.key.keysym.sym == SDLK_LEFT) {
                    player2->dx = -player2->speed;
                }
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    return 0;
                }
                }
            if(event.type == SDL_QUIT) {
                return 0;
            }
        } 
        
        checkMove(player1, &MAP[0][0], WIDTH_SYMB);
        checkMove(player2, &MAP[0][0], WIDTH_SYMB);
        mx_move(player1, &MAP[0][0]);
        mx_move(player2, &MAP[0][0]);
        drawPlayer(player1, renderer);
        drawPlayer(player2, renderer);
        redrawMap(renderer,player1, player2, &MAP[0][0]);
        SDL_Delay(10);
        SDL_RenderPresent(renderer);
    }
   
    clearBulletList(&listBullet, &MAP[0][0]);
    Mix_FreeMusic(backgroundHard);
    Mix_FreeChunk(laser1);
    Mix_FreeChunk(laser2);
    Mix_CloseAudio();
    //IMG_Quit();
    //SDL_Quit();
    return 2;
}
