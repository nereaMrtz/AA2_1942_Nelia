#pragma once
#include <iostream>

#include "Scene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "RenderManager.h"
#include "AnimatedImageRenderer.h"
#include "Tile.h"
#include "Player.h"
#include "SmallNormalPlane.h"
#include "LevelLoader.h"
#include "TextRenderer.h"
#include "HUD.h"



class GameplayScene : public Scene
{
private:

	Tile background;
	Player* player;
	//std::vector<EnemyPlane*> normalPlanes;
	std::vector<Wave*> waves;

	float timer;

	float spawnerTime;

	bool spawn;
	HUD hud;

public:
	GameplayScene();
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;

	void RestartTimer();
	void RestartLevel();

	float levelTime;
};

