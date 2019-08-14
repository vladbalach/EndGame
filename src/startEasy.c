#include "header.h"

static float randomize(float numb) {
    //srand(time(0));
    float plus = rand() % 300;
    numb += numb * (plus / (float)100);
    
    return numb;
}


int startEasy(t_player **player11, t_player **player21, t_player *winPlayer, SDL_Renderer *renderer) {
    char MAP[HEIGHT_SYMB][WIDTH_SYMB];
    clock_t startTime, cd1, cd2;
    startTime = clock();
    cd1 = clock();
    cd2 = clock();
    t_player *player1 = *player11; 
    t_player *player2 = *player21;
    // initPlayers(&player1, &player2);
    //timerTo
    int GAME_STATUS = 0;//
    t_bullet *listBullet = 0;
    // Initialize SDL
    float speedForIteration1 = player1->bulletSpeed;
    float speedForIteration2 = player2->bulletSpeed;
    player2->x = WIDTH_SYMB / 4 * 3 - 1;
    player2->y = HEIGHT_SYMB - 2;
    player1->x = WIDTH_SYMB / 4 - 1;
    player1->y =  HEIGHT_SYMB - 2;
    player1->cloneX = player2->x + 1;
    player2->cloneX = player1->x + 1;
    player1->cloneY = 1;
    player2->cloneY = 1;
    // player1->health = player1->health;
    // player2->health = player2->health;
    //Creating MUSIC channel and adding tracks
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk *laser1 = Mix_LoadWAV("music/laser5.wav");
    Mix_Chunk *laser2 = Mix_LoadWAV("music/laser2.wav");
    Mix_Music *backgroundHard = Mix_LoadMUS("music/Space Sprinkles.mp3");

    // Cxreate a renderer (accelerated and in sync with the display refresh rate)
    SDL_Texture *imgB = IMG_LoadTexture(renderer, "sprites/newback2.png");
    bool running = true;
    Mix_PlayMusic(backgroundHard, -1);
    Mix_VolumeMusic(24);
    SDL_Event event;
    SDL_Rect rectPlayer1 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rectPlayer2 = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    SDL_Rect rect = {0, 0, SIZE_OF_SYMBOL, SIZE_OF_SYMBOL};
    initMap(&MAP[0][0]);
    // Hearts Bar!
    SDL_Rect player1_heart1 = {10, 1210, 96, 32};
    SDL_Texture *player1_heart11 = IMG_LoadTexture(renderer, "sprites/full_bar.png");
    SDL_Rect player1_heart2 = {10, 1210, 96, 32};
    SDL_Texture *player1_heart22 = IMG_LoadTexture(renderer, "sprites/one_grey.png");
    SDL_Rect player1_heart3 = {10, 1210, 96, 32};
    SDL_Texture *player1_heart33 = IMG_LoadTexture(renderer, "sprites/two_grey.png");
    // Player 2 heartbar
    SDL_Rect player2_heart1 = {1820, 1210, 96, 32};
    SDL_Texture *player2_heart11 = IMG_LoadTexture(renderer, "sprites/full_bar.png");
    SDL_Rect player2_heart2 = {1820, 1210, 96, 32};
    SDL_Texture *player2_heart22 = IMG_LoadTexture(renderer, "sprites/one_grey.png");
    SDL_Rect player2_heart3 = {1820, 1210, 96, 32};
    SDL_Texture *player2_heart33 = IMG_LoadTexture(renderer, "sprites/two_grey.png");
    while(running)
    {
       
         speedForIteration1 = player1->bulletSpeed;
         speedForIteration2 = player2->bulletSpeed;
        // if(50000000 < clock() - startTime) {
        //      //printf("%lu\n", startTime);
        //     speedForIteration1 = randomize(player1->bulletSpeed);
        //     speedForIteration2 = randomize(player2->bulletSpeed);
            
        // }
       speedForIteration1 = player1->bulletSpeed + ((float)clock() - (float)startTime)/(float)100000000;
       speedForIteration2 = player2->bulletSpeed + ((float)clock() - (float)startTime)/(float)100000000;
      // printf("%float\n", speedForIteration1);
        player1->dx = 0;
        player1->dy = 0;
        player2->dx = 0;
        player2->dy = 0;
        GAME_STATUS = moveBullet(&listBullet,&MAP[0][0]);
        if(GAME_STATUS == -1) {
            player1->health = (player1->health) - 1;
            printf("First lose");
            printf("%i",player1->health);
            winPlayer = player2;
            SDL_DestroyTexture(imgB);
            SDL_DestroyTexture(player1_heart11);
            SDL_DestroyTexture(player1_heart22);
            SDL_DestroyTexture(player1_heart33);
            SDL_DestroyTexture(player2_heart11);
            SDL_DestroyTexture(player2_heart22);
            SDL_DestroyTexture(player2_heart33);
            clearBulletList(&listBullet, &MAP[0][0]);
            Mix_FreeMusic(backgroundHard);
            Mix_FreeChunk(laser1);
            Mix_FreeChunk(laser2);
            Mix_CloseAudio();
            return 2;
        }
        if(GAME_STATUS == 1) {
            player2->health = (player2->health) - 1;
            printf("Second lose");
            printf("%i",player2->health);
            winPlayer = player1;
            SDL_DestroyTexture(imgB);
            SDL_DestroyTexture(player1_heart11);
            SDL_DestroyTexture(player1_heart22);
            SDL_DestroyTexture(player1_heart33);
            SDL_DestroyTexture(player2_heart11);
            SDL_DestroyTexture(player2_heart22);
            SDL_DestroyTexture(player2_heart33);
            clearBulletList(&listBullet, &MAP[0][0]);
            Mix_FreeMusic(backgroundHard);
            Mix_FreeChunk(laser1);
            Mix_FreeChunk(laser2);
            Mix_CloseAudio();
            return 1;
        }

        SDL_RenderClear(renderer);
        SDL_Rect rect3 = {0, 0, WIDTH_SYMB * SIZE_OF_SYMBOL, HEIGHT_SYMB * SIZE_OF_SYMBOL};
        SDL_RenderCopy(renderer, imgB, NULL, &rect3);
        // Rendering of health bar player 1;
        if (player1->health == 3)
        SDL_RenderCopy(renderer, player1_heart11, NULL, &player1_heart1);
        if (player1->health == 2)
        SDL_RenderCopy(renderer, player1_heart22, NULL, &player1_heart2);
        if (player1->health == 1)
        SDL_RenderCopy(renderer, player1_heart33, NULL, &player1_heart3);
         // Rendering of health bar player 2;
        if (player2->health == 3)
        SDL_RenderCopy(renderer, player2_heart11, NULL, &player2_heart1);
        if (player2->health == 2)
        SDL_RenderCopy(renderer, player2_heart22, NULL, &player2_heart2);
        if (player2->health == 1)
        SDL_RenderCopy(renderer, player2_heart33, NULL, &player2_heart3);

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

    SDL_DestroyTexture(imgB);
    SDL_DestroyTexture(player1_heart11);
    SDL_DestroyTexture(player1_heart22);
    SDL_DestroyTexture(player1_heart33);
    SDL_DestroyTexture(player2_heart11);
    SDL_DestroyTexture(player2_heart22);
    SDL_DestroyTexture(player2_heart33);
    clearBulletList(&listBullet, &MAP[0][0]);
    Mix_FreeMusic(backgroundHard);
    Mix_FreeChunk(laser1);
    Mix_FreeChunk(laser2);
    Mix_CloseAudio();
    return 2;
}
