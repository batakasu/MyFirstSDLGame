#pragma once
#include "MainSceneState.h"

class RouteSelectState : public MainSceneState {
public:
    void Enter(MainScene& context) override;
    void Update(MainScene& context, float deltaTime) override;
    void Draw(MainScene& context) override;
    void Exit(MainScene& context) override;

private:
    int mLeftCard = 0;
    int mRightCard = 0;
    int RollCard();
};