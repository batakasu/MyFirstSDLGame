#include "TitleScene.h"
#include "EventScene.h"

TitleScene::TitleScene(SceneManager& sceneManager, GameContext& context)
    : mSceneManager(sceneManager), mContext(context) {}

void TitleScene::Load() {}

void TitleScene::Update(float deltaTime)
{
    if (mContext.mKeyboard.IsPressed(SDL_SCANCODE_SPACE))
    {
        mSceneManager.ChangeScene<EventScene>(mSceneManager, mContext);
    }
}

void TitleScene::Draw()
{
    // タイトルの描画処理
}

void TitleScene::Unload() {}