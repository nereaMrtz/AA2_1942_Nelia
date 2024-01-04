#include "TextRenderer.h"

TextRenderer::TextRenderer(SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, TTF_Font* font)
{
	this->color = color;
	this->alpha = alpha;
	this->rotation = rotation;
	this->targetRect = targetRect;
	this->sourceRect = sourceRect; 
	this->font = font;
}

void TextRenderer::Load(std::string path)
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, path.c_str(), color);

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);

	SDL_FreeSurface(surface);
}

void TextRenderer::Update()
{
	//SDL_RenderClear(RM->GetRenderer());
}

void TextRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), texture, NULL, &sourceRect);
}

std::string TextRenderer::GetText()
{
	return std::string();
}

void TextRenderer::SetText(std::string Text)
{
}
