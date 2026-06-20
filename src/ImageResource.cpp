#include "ImageResource.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

ImageResource::ImageResource(SDL_Renderer* renderer)
    : mRendererPtr(renderer)
{
}

std::shared_ptr<SDL_Texture> ImageResource::LoadImage(const std::string& filePath)
{
    auto it = mResources.find(filePath);
    if (it != mResources.end())
    {
        if (auto sp = it->second.lock())
        {
            return sp;
        }
    }

    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (!surface)
    {
        SDL_Log("読み込み失敗: %s", SDL_GetError());
        return nullptr;
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(mRendererPtr, surface);

    SDL_DestroySurface(surface);

    if (!texture)
    {
        SDL_Log("描画データ作成失敗: %s", SDL_GetError());
        return nullptr;
    }

    std::shared_ptr<SDL_Texture> sp(
        texture,
        [](SDL_Texture* t)
        {
            SDL_DestroyTexture(t);
        });

    mResources[filePath] = sp;

    return sp;
}