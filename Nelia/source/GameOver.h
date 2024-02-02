#pragma once
#include "Scene.h"
#include "UIText.h"
#include "Tile.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "HighscoreManager.h"

class GameOver : public Scene {
private:
	Tile background;

	UIText backToMenu;
	UIText scoresText;

	TTF_Font* font;

	float buttonAngle;

public:
	GameOver();

	void Update(float dt);
	void Render(SDL_Renderer*);
	void OnEnter();
	void OnExit();
};

