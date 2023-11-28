#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Testing PNG in SDL", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 1280, 720, 0);


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* texA = IMG_LoadTexture(renderer, "images/testimage.png");

    bool run = true;
    SDL_Event event;

    while (run) 
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) 
            {
                run = false;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texA, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
