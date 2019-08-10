#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define IMG_PATH "1.png"
static const int width = 800;
static const int height = 600;
// Draw points with random colors and positions
int main(int argc, char **argv)
{int w, h;
   // Initialize SDL
   SDL_Init(SDL_INIT_VIDEO);
   // Create a SDL window
   SDL_Window *window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 
   SDL_WINDOW_OPENGL);
   // Create a renderer (accelerated and in sync with the display refresh rate)
   SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   bool running = true;
   SDL_Event event;
   int x = 0;
   int dx = 6;
    int dy = 6;
   int y = 0;
   while(running)
   {
       
       SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
       SDL_RenderClear(renderer);
       SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
       SDL_Texture *img = IMG_LoadTexture(renderer, "1.png");
     /*  SDL_Rect texr;
       texr.x = 25;
texr.y = 25;
        texr.w = 25;
        texr.h = 25;*/
      SDL_Rect rect = {x, y, 25, 25};
       x+=dx;
       y+=dy;
      // y+=dx;
       if ((x > width - 25) || (x < 0)) {
           dx = -dx;
      } 
       if ((y > height - 5) || (y < 0)) {
           dy = -dy;
       }
      SDL_RenderCopy(renderer, img, NULL, &rect);
    //  SDL_RenderFillRect(renderer, &rect);
        //SDL_RenderFillRect(renderer, &texr);
   //SDL_RenderPresent(renderer);
       // Process events
       SDL_RenderPresent(renderer);
       while(SDL_PollEvent(&event))
       {
           if(event.type == SDL_QUIT)
           {
               running = false;
           }
       }
      
       //SDL_RenderPresent(renderer);
   }
   // Release resources
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
   return 0;
}