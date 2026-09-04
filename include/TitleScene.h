#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "GameContext.h"
#include "Scene.h"
#include "KeyboardManager.h"
#include <SDL3/SDL.h>

class TitleScene : public Scene
{
public:
    explicit TitleScene(SceneManager& sceneManager, GameContext& context);

    void Load() override;
    void Update(float deltaTime) override;
    void Draw() override;
    void Unload() override;

private:
    SceneManager& mSceneManager;
    GameContext& mContext;
};