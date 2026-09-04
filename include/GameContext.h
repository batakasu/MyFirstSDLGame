#pragma once
#include <string>
#include "KeyboardManager.h"
#include "MouseManager.h"

// プログラム全体で使い、ユニークな集まり
struct GameContext
{
    const std::string mGameTitle;
    KeyboardManager& mKeyboard;
    MouseManager& mMouse;
};