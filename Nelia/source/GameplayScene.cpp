#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	background = Tile(false);
	player = new Player();

	background.LoadTexture(RM->GetRenderer(), "resources/WaterBackground.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 10, 10 }, 0, 0);
	player->LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 1, 1 }, 0, 0);
	player->ChangeSourcePosSize({ 0,0 }, { 32,24 });
	player->SetPosition(RM->windowWidth / 2, RM->windowHeight/2);
}

void GameplayScene::Update(float dt)
{
	if (IM->CheckKeyState(SDLK_UP, DOWN))
		player->AddMovement({ 0, -1 });
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
