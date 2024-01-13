#include "AnimatedImageRenderer.h"

AnimatedImageRenderer::AnimatedImageRenderer(float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, int fps, bool looping, Vector2 scale, int cols=1, int rows=1,int offset=0)
	: ImageRenderer( color, alpha, rotation, targetRect, sourceRect, scale)
{
	this->totalFrames = cols*rows;
	this->fps = fps;
	this->looping = looping;
	this->cols = cols;
	this->rows = rows;
	this->offset = offset;
	firstFramePos = { (float)sourceRect.x, (float)sourceRect.y };
}

void AnimatedImageRenderer::Load(std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	assert(surface);

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(texture);

	totalFrames = cols * rows;
	currentFrame = 0;

	targetRect = SDL_Rect{ 0, 0, 160, 160 };
	sourceRect = SDL_Rect{ sourceRect.x, sourceRect.y, surface->w / cols, surface->h / rows };

	SDL_FreeSurface(surface);
}

void AnimatedImageRenderer::Update()
{
	if (!looping && currentFrame == totalFrames - 1)
		return;

	currentFrameTime += TM->GetDtSec();
	int frameIncrement = (int)(currentFrameTime / maxFrameTime);

	currentFrameTime = ((currentFrameTime / maxFrameTime) - (float)frameIncrement) * maxFrameTime;

	
	currentFrame = (currentFrame + frameIncrement) % totalFrames;
	int frameX = (currentFrame % cols) + (offset * currentFrame);
	int frameY = currentFrame / cols;


	sourceRect = { (sourceRect.w * frameX) + (int)firstFramePos.x, (sourceRect.h * frameY) +(int) firstFramePos.y, sourceRect.w,sourceRect.h };

}

void AnimatedImageRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), texture, &sourceRect, &targetRect);

}

void AnimatedImageRenderer::Reset()
{
	currentFrame = 0;
}
