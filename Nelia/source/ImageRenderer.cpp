#include "ImageRenderer.h"

ImageRenderer::ImageRenderer(SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale) : Renderer(color, alpha, rotation, targetRect, sourceRect, scale)
{
	this->scale = scale;
}

ImageRenderer::~ImageRenderer()
{
	SDL_DestroyTexture(texture);
}

void ImageRenderer::Load(std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);

	//sourceRect = SDL_Rect{ (int)scale.x, (int)scale.y, 255, 255};

	SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);

	//update the destination rect
	targetRect.w = sourceRect.w * scale.x;
	targetRect.h = sourceRect.h * scale.y;

	SDL_FreeSurface(surface);
}

void ImageRenderer::Update()
{
	//SDL_RenderClear(renderer);
}

void ImageRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), texture, &sourceRect, &targetRect);
}
