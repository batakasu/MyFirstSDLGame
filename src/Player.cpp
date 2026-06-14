#include "Player.h"

Player::Player(float x, float y)
{
    this->x = x;
    this->y = y;
    speed = 5.0f;
}

void Player::handleInput(const bool* keys)
{
    if (keys[SDL_SCANCODE_LEFT])  x -= speed;
    if (keys[SDL_SCANCODE_RIGHT]) x += speed;
    if (keys[SDL_SCANCODE_UP])    y -= speed;
    if (keys[SDL_SCANCODE_DOWN])  y += speed;
}

void Player::update()
{
    // 今は空（後で拡張）
}

void Player::render(SDL_Renderer* renderer)
{
    SDL_FRect rect = { x, y, 50, 50 };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}