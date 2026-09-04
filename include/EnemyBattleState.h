#pragma once
#include "MainSceneState.h"

class EnemyBattleState : public MainSceneState {
public:
    void Enter(MainScene& context) override;
    void Update(MainScene& context, float deltaTime) override;
    void Draw(MainScene& context) override;
    void Exit(MainScene& context) override;

private:
    int mEnemyHp = 10;
    int mEnemyPower = 1;
};