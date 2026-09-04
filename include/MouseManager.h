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
    const ButtonState& GetLeft() const {return mLeft;};
    const ButtonState& GetRight() const {return mRight;};
    const ButtonState& GetMiddle() const {return mMiddle;};

private:
    SDL_Cursor* mCursor;
    Vec2 mPosition;

    ButtonState mLeft;
    ButtonState mRight;
    ButtonState mMiddle;
};