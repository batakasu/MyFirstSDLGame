#include "SceneManager.h"

SceneManager::SceneManager(GameContext& gameContext)
    : mGameContext(gameContext)
{
}

SceneManager::~SceneManager() = default;

void SceneManager::Update(float deltaTime)
{
    ProcessTransition();

    if (mCurrentScene)
    {
        mCurrentScene->Update(deltaTime);
    }
}

void SceneManager::Draw()
{
    if (mCurrentScene)
    {
        mCurrentScene->Draw();
    }
}

void SceneManager::ChangeScene(std::unique_ptr<Scene> next)
{
    mNextScene = std::move(next);
}

void SceneManager::ProcessTransition()
{
    if (mNextScene)
    {
        if (mCurrentScene)
        {
            mCurrentScene->Unload();
        }

        mCurrentScene = std::move(mNextScene);
        mCurrentScene->Load();
    }
}