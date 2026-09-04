#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "GameContext.h"

class EventScene : public Scene
{
public:
    explicit EventScene(SceneManager& sceneManager, GameContext& context);

    void Load() override;
    void Update(float deltaTime) override;
    void Draw() override;
    void Unload() override;

private:
    SceneManager& mSceneManager;
    GameContext& mContext;
    int mHp;

    void ApplyChoice(bool accept);
};