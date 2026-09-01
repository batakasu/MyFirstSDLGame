#include "ViewManager.m"

ViewManager(SDL_Renderer* renderer)
    : mRendererPtr(renderer)
    , 
~ViewManager();

ViewId AddView(std::shared_ptr<SDL_Texture> texture, const Vec2& position, const Vec2& size);
UIView* GetView(ViewId id)
{
    mCurrentId += 1;
    return mCurrentId;
}

bool RemoveView(ViewId id)
{
    return true;
}

void DrawAll()
{
    return true;
}