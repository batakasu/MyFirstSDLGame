#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "GameContext.h"
#include <memory>

class MainSceneState;

class MainScene : public Scene
{
public:
    explicit MainScene(SceneManager& sceneManager, GameContext& context);
    ~MainScene();

    void Load() override;
    void Update(float deltaTime) override;
    void Draw() override;
    void Unload() override;

    void ChangeState(std::unique_ptr<MainSceneState> newState);

    SceneManager& GetSceneManager() { return mSceneManager; }
    GameContext& GetGameContext() { return mContext; }

    // ステートから操作・取得するための公開メソッド
    void Heal(int amount);
    void TakeDamage(int amount);
    void AddMoney(int amount);

    int GetHp() const { return mHp; }
    int GetMaxHp() const { return mMaxHp; }
    int GetPower() const { return mPower; }
    int GetDefense() const { return mDefense; }
    int GetMoney() const { return mMoney; }

private:
    SceneManager& mSceneManager;
    GameContext& mContext;
    std::unique_ptr<MainSceneState> mCurrentState;
    std::unique_ptr<MainSceneState> mNextState; // 追加: 次の状態の予約
    bool mIsUpdating = false;

    // プレイヤーのステータス（カプセル化）
    int mHp = 100;
    int mMaxHp = 100;
    int mMoney = 0;
    int mPower = 3;
    int mDefense = 0;
};