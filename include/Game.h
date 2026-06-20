#pragma once
#include <SDL3/SDL.h>

struct GameContext;

class Game
{
public:
    Game(GameContext& gameContext);
    void Run();

private:
    GameContext& mGameContext;
    SDL_Event mEvent;

    void BeginFrame();
    void EndFrame();

    bool mIsRunning = true;
    float mDeltaTime = 0;
    float mLastTime = 0;
};