#pragma once

class ButtonState
{
public:
    void BeginFrame(bool isDown);

    bool IsHeld() const;
    bool IsPressed() const;
    bool IsReleased() const;

private:
    bool mHeld = false;
    bool mPressed = false;
    bool mReleased = false;
};