#include "Game.h"

#include <memory>

#include "GameContext.h"


Game::Game(GameContext& gameContext)
    : mGameContext(gameContext)
{
}

void Game::Run()
{
    while(mIsRunning)
    {
        // Δタイムの計算
        float nowTime = SDL_GetTicks();
        mDeltaTime = (nowTime - mLastTime) / 1000; // 単位を秒に変換
        mLastTime = nowTime;

        // フレーム更新
        while (SDL_PollEvent(&mEvent)) // ユーザーやシステムのイベントを取得する
        {
            if (mEvent.type == SDL_EVENT_QUIT) // ウィンドウの×を押されたら
            {
                mIsRunning = false;
            }
        }

        BeginFrame();

        // ゲームの内部処理

        EndFrame();

    }
}

void Game::BeginFrame()
{
}

void Game::EndFrame()
{
}