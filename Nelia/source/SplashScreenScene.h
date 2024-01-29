#pragma once
#include "Scene.h"
#include "AnimatedImageRenderer.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Tile.h"

#include <iostream>

class SplashScreenScene :public Scene {
private:
	Tile splashScene;
	float time = 0.0f;
	
public:
	SplashScreenScene();

	void SplashScreenRender();
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};