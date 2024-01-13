#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>

#include "Vector2.h"

class Renderer {
protected:
	SDL_Texture* texture;
	SDL_Color color;
	SDL_Rect targetRect; 
	SDL_Rect sourceRect; 

	Vector2 scale;
	Vector2 position;

	float alpha;
	float rotation;


public:
	//******FUNCIONES
	Renderer();
	Renderer(SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale);

	virtual void Load(std::string path) = 0{};
	virtual void Update() = 0{};
	virtual void Render() = 0{};

	//******GETTERS SETTERS
	void SetColor(SDL_Color color);
	void SetAlpha(float alpha);
	void SetPosition(int x, int y);
	void SetRotation(float rotation);
	void SetScale(Vector2 scale);
	void SetSourcePos(Vector2 pos);
	void SetSourceSize(Vector2 size);
	void UpdateTargetRect();

	SDL_Color GetColor();
	float GetAlpha();
};
