#pragma once
#include <string>
#include <memory>
#include <SDL3/SDL.h>
#include "Id.h" 
#include "ImageResource.h"
#include "Vec2.h"
#include "Window.h"
#include "ViewManager.h"   // 追加
#include "ViewFactory.h"   // 追加

class RendererManager
{
public:
    explicit RendererManager(Window& window);
    ~RendererManager();

    SDL_Renderer* GetHandle();
    std::shared_ptr<SDL_Texture> LoadImage(const std::string& filePath);
    ViewId CreateIlustView(const std::string& filePath, const Vec2& position, const Vec2& size);

    void BeginFrame();
    void DrawView();
    void EndFrame();

private:
    SDL_Renderer* mHandle;
    Window& mWindow;
    ImageResource mResources;

    // --- ここに持たせる ---
    ViewManager mViewManager;
    ViewFactory mViewFactory;
};