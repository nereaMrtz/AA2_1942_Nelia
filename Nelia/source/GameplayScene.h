#pragma once
#include "Scene.h"
#include <iostream>
#include "InputManager.h"
#include "SceneManager.h"
#include "RenderManager.h"
#include "AnimatedImageRenderer.h"
#include "Tile.h"
#include "Player.h"
#include "SmallNormalPlane.h"

class GameplayScene : public Scene
{
private:
	Tile background;
	Player* player;
	std::vector<SmallNormalPlane*> normalPlanes;

public:
	GameplayScene();
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};

