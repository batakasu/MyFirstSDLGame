#pragma once
#include <SDL3/SDL.h>
#include "Window.h"
#include "RendererManager.h"
#include "SceneManager.h"
#include "GameContext.h"
#include "Vec2.h"

class Game
{
public:
    explicit Game(GameContext& gameContext);
    ~Game() = default;

    void Run();

private:
    void BeginFrame();
    void EndFrame();

    GameContext& mGameContext;
    Window mWindow;
    RendererManager mRenderer;
    SceneManager mSceneManager;

    SDL_Event mEvent{};
    bool mIsRunning{true};
    float mLastTime{0.0f};
    float mDeltaTime{0.0f};
};