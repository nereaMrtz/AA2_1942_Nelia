#pragma once
#include "Scene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameEngine.h"
#include "UIText.h"
#include "SDL_ttf.h"
#include <iostream>
#include <cassert>

class MainMenuScene : public Scene {
private:
	Tile background;

	UIText playText;
	UIText rankingText;
	UIText audioText;
	UIText exitText;
	TTF_Font* font;

	SDL_Surface* surfacePlay;
	SDL_Surface* surfaceRanking;
	SDL_Surface* surfaceAudio;
	SDL_Surface* surfaceExit;

	SDL_Texture* texturePlay;
	SDL_Texture* textureRanking;
	SDL_Texture* textureAudio;
	SDL_Texture* textureExit;

	float buttonAnglePlay;
	float buttonAngleRanking;
	float buttonAngleAudio;
	float buttonAngleExit;

public:
	MainMenuScene();

	// Inherited via Scene
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;

	void DestroySurfaceAndTexture();
};
