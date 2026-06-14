#include <SDL3/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Move Square", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    float x = 400;
    float y = 300;
    float speed = 5.0f;

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

        // キー入力（押しっぱなし）
        const bool* keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_LEFT])  x -= speed;
        if (keys[SDL_SCANCODE_RIGHT]) x += speed;
        if (keys[SDL_SCANCODE_UP])    y -= speed;
        if (keys[SDL_SCANCODE_DOWN])  y += speed;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_FRect rect = { x, y, 50, 50 };

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}