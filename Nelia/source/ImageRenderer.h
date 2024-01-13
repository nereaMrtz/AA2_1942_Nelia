#pragma once
#include "RenderManager.h"
#include "Renderer.h"

class ImageRenderer : public Renderer {

public:
	ImageRenderer(SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale);

	virtual void Load(std::string path) override;
	virtual void Update() override;
	virtual void Render() override;
};