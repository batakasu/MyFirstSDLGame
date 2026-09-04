#include "ResultScene.h"
#include "TitleScene.h"

ResultScene::ResultScene(SceneManager& sceneManager, GameContext& context, bool clear)
    : mSceneManager(sceneManager), mContext(context), mIsClear(clear) {}

void ResultScene::Load() {}

void ResultScene::Update(float deltaTime)
{
    if (mContext.mKeyboard.IsPressed(SDL_SCANCODE_RETURN))
    {
        mSceneManager.ChangeScene<TitleScene>(mSceneManager, mContext);
    }
}

void ResultScene::Draw()
{
    // 「CLEAR」または「GAME OVER」の描画処理
}

void ResultScene::Unload() {}