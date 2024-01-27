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
		
		//Update
		std::vector<EnemyPlane*> currentPlanes = waves[i]->Update(dt);
		
		for (auto& enemy : currentPlanes) {
			//Check collision between player & enemy planes
			if (player->GetRigidbody().CheckCollision(enemy->GetRigidbody().GetCollider())) {

				std::cout << "HA CHOCAO" << std::endl;
			}
			else
			{
				//std::cout << "no." << std::endl;
			}

			//check collision between enemy planes & player bullets
			for (auto& bullet : player->GetBullets()) {
				if (bullet->GetRigidbody().CheckCollision(enemy->GetRigidbody().GetCollider())) {
					enemy->Destroy();
					bullet->Destroy();
				}
			}
		}

		//for (int i = 0; i < currentPlanes.size(); i++) 
		//{
		//	if (currentPlanes.at(i)->IsPendingDestroy()) 
		//	{
		//		delete currentPlanes[i];	//clear memory
		//		currentPlanes.erase(currentPlanes.begin() + i);
		//		i = 0;
		//	}

		//}
	}

	for (int i = 0; i < player->GetBullets().size(); i++) //TODO: destroy bullets off-screen
	{
		if (player->GetBullets().at(i)->IsPendingDestroy()) 
		{
			delete player->GetBullets()[i];	//clear memory
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

	for (int i = 0; i < waves.size(); i++)
	{
		waves[i]->Render();
	}
}

void GameplayScene::OnEnter()
{
	//LevelLoader loader;
	//waves = loader.LoadWaves("resources/stage_0.xml", levelTime);

}


void GameplayScene::OnExit()
{
}
