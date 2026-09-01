#pragma once
#include <SDL3/SDL.h>
#include "Window.h"
#include "RendererManager.h"

struct GameContext;

class Game
{
public:
    Game(GameContext& gameContext);
    void Run();

private:
    GameContext& mGameContext;
    SDL_Event mEvent;
    Window mWindow;
    RendererManager mRenderer;

    void BeginFrame();
    void EndFrame();

    bool mIsRunning = true;
    float mDeltaTime = 0;
    float mLastTime = 0;
};