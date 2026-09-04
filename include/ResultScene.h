#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "GameContext.h"

class ResultScene : public Scene
{
public:
    explicit ResultScene(SceneManager& sceneManager, GameContext& context, bool clear);

    void Load() override;
    void Update(float deltaTime) override;
    void Draw() override;
    void Unload() override;

private:
    SceneManager& mSceneManager;
    GameContext& mContext;
    bool mIsClear;
};