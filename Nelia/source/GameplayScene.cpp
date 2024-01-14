#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	background = Tile(false);
	player = new Player();

	for (int i = 0; i < 4; i++)
	{
		int random = rand() % 5 + 2;

		auto enemy = new SmallNormalPlane(V);
		enemy->LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,160, 512, 512 }, { 1, 1 }, 0, 0, false, 0);
		enemy->ChangeSourcePosSize({ 0,0 }, { 24,16 }, 0);
		enemy->SetPosition(RM->windowWidth / random, RM->windowHeight / 6);
		//std::cout << random <<" "<< random << std::endl;
		normalPlanes.push_back(enemy);

	}

	background.LoadTexture(RM->GetRenderer(), "resources/WaterBackground.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 10, 10 }, 0, 0, false, 0);
}

void GameplayScene::Update(float dt)
{
	player->Update(dt);

	int i = 0;
	for (auto enemy : normalPlanes) {
		enemy->Update(dt);

		if (player->GetRigidbody().CheckCollision(enemy->GetRigidbody().GetCollider())) {

			std::cout << "HA CHOCAO" << std::endl;
		}
		else
		{
			std::cout << "no." << std::endl;
		}
		
		for (auto bullet : player->GetBullets()) {
			if (bullet->GetRigidbody().CheckCollision(enemy->GetRigidbody().GetCollider())) {
				enemy->Destroy();
			}
		}
		i++;
	}

	for (auto it = normalPlanes.begin(); it != normalPlanes.end(); it++) {
		if ((*it)->IsPendingDestroy()) {
			normalPlanes.erase(it);
			it = normalPlanes.begin();
		}
	}

}

void GameplayScene::Render(SDL_Renderer*)
{
	background.Render();
	player->Render();

	for (auto enemy : normalPlanes)
		enemy->Render();
}

void GameplayScene::OnEnter()
{
}

void GameplayScene::OnExit()
{
}
