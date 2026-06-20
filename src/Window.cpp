#include "Window.h"
#include "GameContext.h"

Window::Window(GameContext& gameContext, Vec2 size)
    : mGameContext(gameContext)
    , mSize(size)
{
   mHandle = SDL_CreateWindow
(
    gameContext.mGameTitle.c_str(),
    static_cast<int>(size.mX),
    static_cast<int>(size.mY),
    SDL_WINDOW_RESIZABLE
);
}

Window::~Window()
{
    SDL_DestroyWindow(mHandle);
}

SDL_Window* Window::GetHandle()
{
    return mHandle;
}

Vec2 Window::GetSize()
{
    return mSize;
}