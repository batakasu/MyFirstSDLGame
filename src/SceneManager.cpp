#include "SceneManager.h"

SceneManager::SceneManager(GameContext& gameContext)
    : mGameContext(gameContext)
{
}

SceneManager::~SceneManager() = default;

void SceneManager::Update()
{
    mCurrentScene->Update();
}

void SceneManager::ChangeScene(std::unique_ptr<Scene> next)
{
    if (mCurrentScene) mCurrentScene->Unload();

    mCurrentScene = std::move(next);
    mCurrentScene->Load();
}