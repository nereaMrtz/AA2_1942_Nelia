#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	background = Tile(false);
	player = new Player();

	background.LoadTexture(RM->GetRenderer(), "resources/WaterBackground.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 10, 10 }, 0, 0, false, 0);

	LevelLoader loader;
	waves = loader.LoadWaves("resources/stage_0.xml", levelTime);

	timer = 0;
	spawnerTime = 0;
	spawn = false;
}

void GameplayScene::Update(float dt)
{

	player->Update(dt);

	for (int i = 0; i < waves.size(); i++) {

		if(waves[1])
		normalPlanes = waves[i]->SpawnPlanes(dt);
			
	}

	//std::cout << timer << std::endl;

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
				bullet->Destroy();
			}
		}
	}

	for (int i = 0; i < normalPlanes.size(); i++) {
		
		if (normalPlanes.at(i)->IsPendingDestroy()) {
			normalPlanes.erase(normalPlanes.begin()+i);
			i = 0;
		}
		
	}

	for (int i = 0; i < player->GetBullets().size(); i++) {
		if (player->GetBullets().at(i)->IsPendingDestroy()) {
			player->GetBullets().erase(player->GetBullets().begin() + i);
			i = 0;
		}
	}
	timer += dt;
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
	//LevelLoader loader;
	//waves = loader.LoadWaves("resources/stage_0.xml", levelTime);

}


void GameplayScene::OnExit()
{
}
