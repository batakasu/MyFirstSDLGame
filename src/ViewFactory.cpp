#include "ViewFactory.h"
#include "ViewManager.h"
// #include "ImageResource.h" // 必要に応じて追加

ViewFactory::ViewFactory(SDL_Renderer* renderer, ImageResource& resources, ViewManager& viewManager)
    : mRendererPtr(renderer)
    , mResources(resources)
    , mViewManager(viewManager)
{
}

ViewId ViewFactory::CreateIlustView(const std::string& filePath, const Vec2& position, const Vec2& size)
{
    // 実装例（ImageResource と ViewManager の仕様に合わせて調整してください）
    // std::shared_ptr<SDL_Texture> texture = mResources.LoadTexture(mRendererPtr, filePath);
    // return mViewManager.AddView(texture, position, size);
    
    return ViewId{}; // プレースホルダーの戻り値
}