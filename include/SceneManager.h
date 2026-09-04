#pragma once
#include <memory>
#include <utility>
#include "Scene.h"

struct GameContext;

class SceneManager
{
public:
    explicit SceneManager(GameContext& gameContext);
    ~SceneManager();

    void Update(float deltaTime);
    void Draw();
    void ChangeScene(std::unique_ptr<Scene> next);

private:
    GameContext& mGameContext;
    std::unique_ptr<Scene> mCurrentScene;
    std::unique_ptr<Scene> mNextScene;

    void ProcessTransition();
};