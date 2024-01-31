#pragma once
#include "UIText.h"
#include "SDL_ttf.h"
#include "RenderManager.h"
#include <cassert>
class HUD
{
private:
	UIText scoreText;
	UIText scoreNum;
	TTF_Font* font;
	int score;

public:
	HUD();
	void Render();
	void UpdateScore(int score);
};

