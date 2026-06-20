#include "ButtonState.h"

void ButtonState::BeginFrame(bool isDown)
{
    mPressed  = (isDown && !mHeld);
    mReleased  = (!isDown && mHeld);
    mHeld = isDown;
}

bool ButtonState::IsHeld() const
{
    return mHeld;
}

bool ButtonState::IsPressed() const
{
    return mPressed;
}

bool ButtonState::IsReleased() const
{
    return mReleased;
}