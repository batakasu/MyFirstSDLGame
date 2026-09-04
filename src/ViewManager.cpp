#include "ViewManager.h"
#include "UIView.h"

ViewManager::ViewManager(SDL_Renderer* renderer)
    : mRendererPtr(renderer)
    , mCurrentId(0)
{
}

ViewManager::~ViewManager() = default;

ViewId ViewManager::AddView(std::shared_ptr<SDL_Texture> texture, const Vec2& position, const Vec2& size)
{
    // ビューの追加処理をここに記述
    mCurrentId = ViewId(mCurrentId.Get() + 1); // 強制型付きIDの加算例
    return mCurrentId;
}

UIView* ViewManager::GetView(ViewId id)
{
    // IDに対応するUIView*を返す処理
    // 例: マップ等から検索して返す
    return nullptr; 
}

bool ViewManager::RemoveView(ViewId id)
{
    // 削除処理
    return true;
}

void ViewManager::DrawAll()
{
    // 描画処理（void なので値を返さない）
}