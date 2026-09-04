#include "KeyboardManager.h"

void KeyboardManager::BeginFrame()
{
    const bool* state = SDL_GetKeyboardState(nullptr);
    for(int i=0; i<SDL_SCANCODE_COUNT; i++)
    {
        bool now = (state[i] != 0);
        mCurrent[i].BeginFrame(now);
    }
}

bool KeyboardManager::IsPressed(SDL_Scancode key) const
{
    return mCurrent[key].IsPressed();
}

bool KeyboardManager::IsHeld(SDL_Scancode key) const
{
    return mCurrent[key].IsHeld();
}

bool KeyboardManager::IsReleased(SDL_Scancode key) const
{
    return mCurrent[key].IsReleased();
}