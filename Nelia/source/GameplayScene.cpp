#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	background = Tile(false);
	player = new Player(new Spawner());
	player->SetPosition(RM->windowWidth / 2, RM->windowHeight);

	background.LoadTexture(RM->GetRenderer(), "resources/WaterBackground.png", false, {0,0, 512, 512}, { 0,0, 512, 512}, {10, 10});
	player->LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 1, 1 });
	player->transform.position = { 0,0 };
	//player->GetRenderer()->
}

void GameplayScene::Update(float dt)
{
	if (IM->CheckKeyState(SDLK_UP, DOWN))
		player->AddMovement({0, -1});
}

void GameplayScene::Render(SDL_Renderer*)
{
	//background.Render();
	player->Render();
}

void GameplayScene::OnEnter()
{
}

void GameplayScene::OnExit()
{
}
