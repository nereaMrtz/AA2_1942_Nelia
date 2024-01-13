#include "Renderer.h"

// SDL_Rect{ controls the rect's x coordinate, controls the rect's y coordinate, 
			//controls the width of the rect, controls the width of the rect}

void Renderer::SetSourcePos(Vector2 pos)
{
	targetRect.x = pos.x;
	targetRect.y = pos.y;
}

void Renderer::SetSourceSize(Vector2 size)
{
	sourceRect.w = size.x;
	sourceRect.h = size.y;
}

void Renderer::UpdateTargetRect()
{
	targetRect.w = sourceRect.w * scale.x;
	targetRect.h = sourceRect.h * scale.y;
}

Renderer::Renderer() {

}

Renderer::Renderer(SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale)
{
	this->color = color;
	this->alpha = alpha;
	this->rotation = rotation;
	this->targetRect = targetRect;
	this->sourceRect = sourceRect;
	this->scale = scale;

}

void Renderer::SetColor(SDL_Color color)
{
	this->color = color;
}

void Renderer::SetAlpha(float alpha)
{
	this->alpha = alpha;
}

void Renderer::SetPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
	this->targetRect.x = position.x - (targetRect.w / 2);
	this->targetRect.y = position.y - (targetRect.h / 2);
}

void Renderer::SetRotation(float rotation)
{
	this->rotation = rotation;
}

void Renderer::SetScale(Vector2 scale)
{
	this->scale = scale;
}

SDL_Color Renderer::GetColor()
{
	return color;
}

float Renderer::GetAlpha()
{
	return alpha;
}
