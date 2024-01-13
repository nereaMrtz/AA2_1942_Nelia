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

	GameObject() : Object() {

	}

	void LoadTexture(SDL_Renderer* renderer, std::string path, bool isAnimated, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale);
	void SetPosition(int x, int y);
	virtual void Update(float dt);
	virtual void Render();
	Renderer* GetRenderer();
protected:
	std::vector<ImageRenderer*> renderer;	
};
