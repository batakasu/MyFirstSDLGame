#pragma once
#include <memory>
#include "GameContext.h"
#include "Scene.h"

class SceneManager
{
public:
    explicit SceneManager(GameContext& gameContext);
    ~SceneManager();
    void Update();
    void ChangeScene(std::unique_ptr<Scene> next);

private:
    GameContext& mGameContext;
    std::unique_ptr<Scene> mCurrentScene;

};