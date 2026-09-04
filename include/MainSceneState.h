#pragma once

class MainScene;

class MainSceneState {
public:
    virtual ~MainSceneState() = default;

    // ステートに入った時の初期化処理
    virtual void Enter(MainScene& context) = 0;

    // 毎フレームの更新処理（入力・ゲームロジック）
    virtual void Update(MainScene& context, float deltaTime) = 0;

    // 描画処理
    virtual void Draw(MainScene& context) = 0;

    // ステートから出る時の終了処理
    virtual void Exit(MainScene& context) = 0;
};