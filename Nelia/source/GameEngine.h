#pragma once
#include<SDL.h>
#include"InputManager.h"
#include "SceneManager.h"
#include "SplashScreenScene.h"
#include "GameplayScene.h"
#include "MainMenuScene.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include "Tile.h"

class GameEngine
{
private:
	bool isRunning;
	Tile logo;

public:
	GameEngine(int x, int y);
	void Init();
	void Run();
	void Quit();

};
