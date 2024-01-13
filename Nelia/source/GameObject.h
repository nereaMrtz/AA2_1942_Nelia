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

	void LoadTexture(SDL_Renderer* renderer, std::string path, bool isAnimated, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale, int rows, int cols, bool looping, int offset);
	void ChangeSourcePosSize(Vector2 pos, Vector2 size, int i);
	virtual void SetPosition(int x, int y);
	virtual void Update(float dt);
	virtual void Render();
	Renderer* GetRenderer();
protected:
	std::vector<ImageRenderer*> renderer;	
};
