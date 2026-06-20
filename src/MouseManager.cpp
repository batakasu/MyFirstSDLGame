#include "MouseManager.h"

MouseManager::MouseManager()
    : mCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_DEFAULT))
{
    SDL_SetCursor(mCursor);
}

MouseManager::~MouseManager()
{
    SDL_DestroyCursor(mCursor);
}

void MouseManager::BeginFrame()
{
    SDL_MouseButtonFlags buttons = SDL_GetMouseState(&mPosition.mX, &mPosition.mY);

    bool leftNow = (buttons & SDL_BUTTON_MASK(SDL_BUTTON_LEFT)) != 0;

    bool rightNow = (buttons & SDL_BUTTON_MASK(SDL_BUTTON_RIGHT)) != 0;

    bool middleNow = (buttons & SDL_BUTTON_MASK(SDL_BUTTON_MIDDLE)) != 0;

    mLeft.BeginFrame(leftNow);
    mRight.BeginFrame(rightNow);
    mMiddle.BeginFrame(middleNow);
}

Vec2 MouseManager::GetPosition() const 
{
    return mPosition;
}

ButtonState MouseManager::GetLeft() const
{
    return mLeft;
}

ButtonState MouseManager::GetRight() const
{
    return mRight;
}

ButtonState MouseManager::GetMiddle() const
{
    return mMiddle;
}