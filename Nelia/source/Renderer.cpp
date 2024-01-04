#include "Renderer.h"

// SDL_Rect{ controls the rect's x coordinate, controls the rect's y coordinate, 
			//controls the width of the rect, controls the width of the rect}

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

void Renderer::SetPosition(Vector2 position)
{
	this->position = position;
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
