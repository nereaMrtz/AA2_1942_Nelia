#pragma once
#include "Renderer.h"
#include "RenderManager.h"

class TextRenderer : public Renderer
{
private:
	std::string text;
	TTF_Font* font;

public:
	TextRenderer(SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, TTF_Font* font);
	
	virtual void Load(std::string path) override;
	virtual void Update() override;
	virtual void Render() override;

	std::string GetText();

	void SetText(std::string Text);
};

