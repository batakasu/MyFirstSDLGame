#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <SDL3/SDL.h> 
#include "Id.h"
#include "Vec2.h"

struct SDL_Renderer;

class UIView;

class ViewManager
{
public:
	ViewManager(SDL_Renderer* renderer);
    ~ViewManager();

    ViewId AddView(std::shared_ptr<SDL_Texture> texture, const Vec2& position, const Vec2& size);
    UIView* GetView(ViewId id);

    bool RemoveView(ViewId id);
    void DrawAll();

private:
	SDL_Renderer* mRendererPtr;
    ViewId mCurrentId = 0;
    std::unordered_map<ViewId, std::unique_ptr<UIView>> mViews;
};