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
	SDL_Surface* surface;
	SDL_Texture* texture;

	UIText resume;

	TTF_Font* font;

	float buttonAngle;
	float timer;

public:
	PauseMenu();

	void Update(float dt);
	void Render(SDL_Renderer*);
	void OnEnter();
	void OnExit();

	void DestroySurfaceAndTexture();
};

