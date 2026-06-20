#include "Game.h"
#include "GameContext.h"
#include "MouseManager.h"
#include "KeyboardManager.h"

int main(int argc, char* argv[])
{
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