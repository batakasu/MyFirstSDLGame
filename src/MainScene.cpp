#include "EventScene.h"
#include "ResultScene.h"

EventScene::EventScene(SceneManager& sceneManager, GameContext& context)
    : mSceneManager(sceneManager), mContext(context), mHp(100) {}

void EventScene::Load() {}

void EventScene::Update(float deltaTime)
{
    if (mContext.mKeyboard.IsPressed(SDL_SCANCODE_A))
    {
        ApplyChoice(true);
    }
    else if (mContext.mKeyboard.IsPressed(SDL_SCANCODE_R))
    {
        ApplyChoice(false);
    }
}

void EventScene::Draw()
{
    // 描画処理
}

void EventScene::Unload() {}

void EventScene::ApplyChoice(bool accept)
{
    mHp -= accept ? 30 : 10;
    if (mHp <= 0)
    {
        mSceneManager.ChangeScene<ResultScene>(mSceneManager, mContext, false);
    }
}
