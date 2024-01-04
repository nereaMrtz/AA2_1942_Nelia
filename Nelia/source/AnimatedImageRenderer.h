#pragma once
#include "ImageRenderer.h"
#include "RenderManager.h"
#include "TimeManager.h"

class AnimatedImageRenderer : public ImageRenderer{
private:
	int fps;
	int totalFrames;
	
	bool looping = true;

	float frameTime;

	int rows, cols, currentFrame;

	float lastGameTime = 0.0f;

	float currentFrameTime = 0.0f;
	float maxFrameTime = 1.f / 28.f;



public:
	AnimatedImageRenderer(float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect, int fps, bool looping, int totalFrames, Vector2 scale);
	
	virtual void Load(std::string path) override;
	virtual void Update() override;
	virtual void Render() override;
};

