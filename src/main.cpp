#include <SDL3/SDL.h>
#include "Player.h"

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Player Class", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    Player player(400, 300);

    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        const bool* keys = SDL_GetKeyboardState(NULL);

        player.handleInput(keys);
        player.update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        player.render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}