#pragma once
#include <SDL3/SDL_mouse.h>
#include "ButtonState.h"
#include "Vec2.h"

class MouseManager
{
public:
    MouseManager();
    ~MouseManager();

    void BeginFrame();
    Vec2 GetPosition() const;
    ButtonState GetLeft() const;
    ButtonState GetRight() const;
    ButtonState GetMiddle() const;
    
private:
    SDL_Cursor* mCursor;
    Vec2 mPosition;

    ButtonState mLeft;
    ButtonState mRight;
    ButtonState mMiddle;
};