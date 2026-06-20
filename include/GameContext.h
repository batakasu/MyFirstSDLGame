#pragma once
#include <string>

class MouseManager;
class KeyboardManager;

// プログラム全体で使い、ユニークな集まり
struct GameContext
{
    const std::string mGameTitle;
    MouseManager& mMouse;
    KeyboardManager& mKeyboard;
};