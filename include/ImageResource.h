#pragma once
#include <memory>
#include <string>
#include <unordered_map>

struct SDL_Texture;
struct SDL_Renderer;

class ImageResource
{
public:
	ImageResource(SDL_Renderer* renderer);
	std::shared_ptr<SDL_Texture> LoadImage(const std::string& filePath);
	
private:
	SDL_Renderer* mRendererPtr;
	std::unordered_map<std::string, std::weak_ptr<SDL_Texture>> mResources; // key == filePath
};