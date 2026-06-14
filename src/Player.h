#pragma once
#include <SDL3/SDL.h>

class Player
{
public:
    Player(float x, float y);

    void handleInput(const bool* keys);
    void update();
    void render(SDL_Renderer* renderer);

private:
    float x, y;
    float speed;
};