#pragma once
#include <string>
#include <memory>
#include <SDL.h>
#include "Vec2.h"
#include "Window.h"

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
};