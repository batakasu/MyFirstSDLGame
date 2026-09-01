#pragma once
#include <SDL3/SDL_mouse.h>
#include <ViewFactory.h>
#include <ViewManager.h>
#include "Vec2.h"

class GameContext;

// windowを複数生成することも可能
class Window
{
public:
    Window(GameContext& gameContext, Vec2 size);
    ~Window();
    SDL_Window* GetHandle();
    Vec2 GetSize();
    
private:
    GameContext& mGameContext;
    Vec2 mSize;
    SDL_Window* mHandle;
    ViewFactory mFactory;
    ViewManager mManager;
};