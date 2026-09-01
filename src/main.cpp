#include <SDL3/SDL.h>

#include "Game.h"
#include "GameContext.h"
#include "MouseManager.h"
#include "KeyboardManager.h"

int main(int argc, char* argv[])
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    MouseManager mouse;
    KeyboardManager keyboard;

    GameContext gameContext
    {
        "AdmitRefuse",
        mouse,
        keyboard
    };

    Game game(gameContext);

    game.Run();

    return 0;
}