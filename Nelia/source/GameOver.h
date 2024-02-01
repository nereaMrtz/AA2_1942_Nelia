#pragma once
#include "Scene.h"
#include "UIText.h"
#include "Tile.h"
#include "InputManager.h"
#include "AudioManager.h"

class GameOver : public Scene {
private:
	Tile background;

	UIText backToMenu;

	TTF_Font* font;

	float buttonAngle;

public:
	GameOver();

	void Update(float dt);
	void Render(SDL_Renderer*);
	void OnEnter();
	void OnExit();
};

