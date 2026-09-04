#include "TitleScene.h"
#include "MainScene.h"

TitleScene::TitleScene(SceneManager& sceneManager, GameContext& context)
    : mSceneManager(sceneManager), mContext(context) {}

void TitleScene::Load()
{
    SDL_Log("タイトルシーン");
}

void TitleScene::Update(float deltaTime)
{
    if (mContext.mKeyboard.IsPressed(SDL_SCANCODE_SPACE))
    {
        mSceneManager.ChangeScene(std::make_unique<MainScene>(mSceneManager, mContext));
    }
}

void TitleScene::Draw()
{
    // タイトルの描画処理
}

void TitleScene::Unload() {}