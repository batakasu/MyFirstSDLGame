#include "RendererManager.h"

RendererManager::RendererManager(Window& window)
    : mHandle(SDL_CreateRenderer(window.GetHandle(), nullptr))
    , mWindow(window)
    , mResources(mHandle)
    , mViewManager(mHandle)
{
}

RendererManager::~RendererManager()
{
    SDL_DestroyRenderer(mHandle);
}

SDL_Renderer* RendererManager::GetHandle()
{
    return mHandle;
}

std::shared_ptr<SDL_Texture> RendererManager::LoadImage(const std::string& filePath)
{
    return mResources.LoadImage(filePath);
}

ViewId RendererManager::CreateIlustView(const std::string& filePath, const Vec2& position, const Vec2& size)
{
    auto texture = mResources.LoadImage(filePath);
    return mViewManager.AddView(texture, position, size);
}

void RendererManager::BeginFrame()
{
    SDL_RenderClear(mHandle);
}

void RendererManager::DrawView()
{
    mViewManager.DrawAll();
}

void RendererManager::EndFrame()
{
    SDL_RenderPresent(mHandle);
}