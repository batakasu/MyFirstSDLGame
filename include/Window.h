#pragma once
#include <SDL3/SDL_mouse.h>
#include "Vec2.h"

class GameContext;

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
};