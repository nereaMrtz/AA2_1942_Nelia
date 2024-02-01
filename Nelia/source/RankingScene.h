#pragma once
#include "Scene.h"
#include "UIText.h"
#include "Tile.h"
#include "InputManager.h"
#include "AudioManager.h"

class RankingScene :  public Scene
{
private:

	Tile background;

	UIText backToMenu;

	TTF_Font* font;

	float buttonAngle;

public:
	RankingScene();
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
	void OnEnter() override;
	void OnExit() override;
};

