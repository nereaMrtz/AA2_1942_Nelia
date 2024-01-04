#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	background = Tile(false);
	//frog = Frog();

	background.LoadTexture(RM->GetRenderer(), "resources/background.png", false, {0,0, 274, 209}, { 0,0, 274, 209}, {3, 3});
	//frog.LoadTexture(RM->GetRenderer(), "resources/frog.png", true, {0, 0, 160, 160}, {0, 0, 320, 160}, {1, 1});
}

void GameplayScene::Update(float dt)
{
	//frog.Update();
}

void GameplayScene::Render(SDL_Renderer*)
{
	background.Render();
	//frog.Render();
}

void GameplayScene::OnEnter()
{
}

void GameplayScene::OnExit()
{
}
