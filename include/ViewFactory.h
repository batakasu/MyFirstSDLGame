#pragma once
#include <string>
#include "ImageResource.h"
#include "Vec2.h"
#include "Id.h"

struct SDL_Renderer;
class ViewManager;

class ViewFactory
{
public:
    ViewFactory(SDL_Renderer* renderer, ImageResource& resources, ViewManager& viewManager);
    ViewId CreateIlustView(const std::string& filePath, const Vec2& position, const Vec2& size);

private:
	SDL_Renderer* mRendererPtr;
    ImageResource& mResources;
    ViewManager& mViewManager;
};