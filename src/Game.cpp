#include "Game.h"
#include "TitleScene.h"

Game::Game(GameContext& gameContext)
    : mGameContext(gameContext)
    , mWindow(gameContext, Vec2(1280, 720))
    , mRenderer(mWindow)
    , mSceneManager(gameContext)
    , mLastTime(static_cast<float>(SDL_GetTicks()))
{
    // 初期シーンとしてタイトルを設定
    mSceneManager.ChangeScene(std::make_unique<TitleScene>(mSceneManager, mGameContext));
}

void Game::Run()
{
    while (mIsRunning)
    {
        // Δタイムの計算
        float nowTime = static_cast<float>(SDL_GetTicks());
        mDeltaTime = (nowTime - mLastTime) / 1000.0f;
        mLastTime = nowTime;

        // イベント処理
        while (SDL_PollEvent(&mEvent))
        {
            if (mEvent.type == SDL_EVENT_QUIT)
            {
                mIsRunning = false;
            }
        }

        // 入力マネージャーのフレーム更新
        mGameContext.mKeyboard.BeginFrame();
        mGameContext.mMouse.BeginFrame();

        BeginFrame();

        // ゲームの内部処理（シーンの更新と描画）
        mSceneManager.Update(mDeltaTime);
        mSceneManager.Draw();

        EndFrame();
    }
}

void Game::BeginFrame()
{
    mRenderer.BeginFrame();
}

void Game::EndFrame()
{
    mRenderer.EndFrame();
}