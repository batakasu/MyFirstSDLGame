#pragma once
#include <memory>
#include <utility>
#include "Scene.h"

class SceneManager;

class Scene {
public:
    virtual ~Scene() = default;
    virtual void Load() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    virtual void Unload() = 0;
};