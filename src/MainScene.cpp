#include "MainScene.h"
#include "MainSceneState.h"     // 1. 基底クラスを先にインクルードする
#include "RouteSelectState.h"   // 2. その後に派生クラスをインクルードする
#include <memory>
#include <utility>

MainScene::MainScene(SceneManager& sceneManager, GameContext& context)
    : mSceneManager(sceneManager)
    , mContext(context)
    , mIsUpdating(false)
{
}

MainScene::~MainScene() = default;

void MainScene::Load()
{
    ChangeState(std::make_unique<RouteSelectState>());
}

void MainScene::Update(float deltaTime)
{
    mIsUpdating = true;
    if (mCurrentState) {
        mCurrentState->Update(*this, deltaTime);
    }
    mIsUpdating = false;

    // Updateの処理が終わった安全なタイミングで状態を切り替える
    if (mNextState) {
        if (mCurrentState) {
            mCurrentState->Exit(*this);
        }
        mCurrentState = std::move(mNextState);
        if (mCurrentState) {
            mCurrentState->Enter(*this);
        }
    }
}

void MainScene::Draw()
{
    if (mCurrentState) {
        mCurrentState->Draw(*this);
    }
}

void MainScene::Unload()
{
    if (mCurrentState) {
        mCurrentState->Exit(*this);
        mCurrentState.reset();
    }
}

void MainScene::ChangeState(std::unique_ptr<MainSceneState> newState)
{
    if (mIsUpdating) {
        // 更新中の呼び出しなら、Update終了後に切り替えるよう予約する
        mNextState = std::move(newState);
    } else {
        // Load時など、更新中でなければ即座に切り替える
        if (mCurrentState) {
            mCurrentState->Exit(*this);
        }
        mCurrentState = std::move(newState);
        if (mCurrentState) {
            mCurrentState->Enter(*this);
        }
    }
}

void MainScene::Heal(int amount)
{
    mHp += amount;
    if (mHp > mMaxHp) {
        mHp = mMaxHp;
    }
}

void MainScene::TakeDamage(int amount)
{
    int dmg = (amount - mDefense > 0) ? (amount - mDefense) : 0;
    mHp -= dmg;
    if (mHp < 0) {
        mHp = 0;
    }
}

void MainScene::AddMoney(int amount)
{
    mMoney += amount;
}