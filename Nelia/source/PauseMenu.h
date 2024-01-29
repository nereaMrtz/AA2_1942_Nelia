#pragma once
#include "Scene.h"
#include "GameState.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "UIText.h"
#include "SDL_ttf.h"
#include "Tile.h"
#include "GameplayScene.h"
#include <iostream>
#include <cassert>

class PauseMenu : public Scene{
private:
	Tile background;

	UIText resume;

	GameState states;
	Scene* gameplayState;

	TTF_Font* font;

	float buttonAngle;

public:
	PauseMenu();

	void Update(float dt);
	void Render(SDL_Renderer*);
	void OnEnter();
	void OnExit();
};

