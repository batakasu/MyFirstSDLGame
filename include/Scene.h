#pragma once

class Scene
{
public:
    virtual ~Scene() = default;

    virtual void Load() = 0;
    virtual void Update() = 0;
    virtual void Unload() = 0; 

private:

};
