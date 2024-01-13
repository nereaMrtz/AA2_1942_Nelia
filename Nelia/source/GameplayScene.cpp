#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	background = Tile(false);
	player = new Player();

	background.LoadTexture(RM->GetRenderer(), "resources/WaterBackground.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 10, 10 }, 0, 0, false, 0);

	player->SetPosition(RM->windowWidth / 2, RM->windowHeight/2);
}

void GameplayScene::Update(float dt)
{
	player->Update(dt);
}

void GameplayScene::Render(SDL_Renderer*)
{
	background.Render();
	player->Render();
}

void GameplayScene::OnEnter()
{
}

void GameplayScene::OnExit()
{
}
