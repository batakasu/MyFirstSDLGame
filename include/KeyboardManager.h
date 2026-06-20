#pragma once
#include <array>
#include <SDL3/SDL.h> 
#include "ButtonState.h"

class KeyboardManager
{
public:
    void BeginFrame();
    bool IsHeld(SDL_Scancode key) const;
    bool IsPressed(SDL_Scancode key) const;
    bool IsReleased(SDL_Scancode key) const;

private:
    std::array<ButtonState, SDL_SCANCODE_COUNT> mCurrent{};
};