#pragma once
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include <vector>

#include "Object.h"
#include "ImageRenderer.h"
#include "AnimatedImageRenderer.h"

class GameObject : public Object
{
public:
	GameObject() = default;
	void LoadTexture(SDL_Renderer* renderer, std::string path, bool isAnimated, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale);
	void SetPosition(int x, int y);
	void Update() = 0;
	void Render() = 0;
	Renderer* GetRenderer();
protected:
	std::vector<ImageRenderer*> renderer;	
};
