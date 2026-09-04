#pragma once
#include <memory>
#include <utility>
#include "Scene.h"

class SceneManager
{
public:
    template <typename T, typename... Args>
    void ChangeScene(Args&&... args)
    {
        mNextScene = std::make_unique<T>(std::forward<Args>(args)...);
    }

    void Update(float deltaTime);
    void Draw();

private:
    std::unique_ptr<Scene> mCurrentScene;
    std::unique_ptr<Scene> mNextScene;

    void PerformTransition();
};