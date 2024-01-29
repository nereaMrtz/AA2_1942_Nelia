#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	states = GameState::GAMEPLAY;
	background = Tile(false);
	player = new Player();
	death = false;

	background.LoadTexture(RM->GetRenderer(), "resources/WaterBackground.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 10, 10 }, 0, 0, false, 0);

	LevelLoader loader;
	waves = loader.LoadWaves("resources/stage_0.xml", levelTime);

	timer = 0;
	spawnerTime = 0;
	spawn = false;
}

void GameplayScene::Update(float dt)
{
	switch (states)
	{
	case GameState::GAMEPLAY:

		player->Update(dt);

		for (int i = 0; i < waves.size(); i++) {

			//Update
			std::vector<EnemyPlane*> currentPlanes = waves[i]->Update(dt);

			for (auto& enemy : currentPlanes) {
				//Check collision between player & enemy planes
				if (player->GetRigidbody().CheckCollision(enemy->GetRigidbody().GetCollider())) {

					player->Death();
					enemy->Destroy();
					std::cout << "chocaaao" << std::endl;
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
		std::cout << timer << std::endl;

		if (IM->CheckKeyState(SDLK_ESCAPE, PRESSED)) {
			states = PAUSED;
			break;
		}
		break;
	case GameState::PAUSED:
		SM->SetScene("Pause Menu");
		std::cout << "PAUSADO";
		states = GAMEPLAY;
		break;
	case GameState::FINISH_STAGE:
		break;
	case GameState::DEATH:
		break;
	default:
		break;
	}
	
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


void GameplayScene::RestartTimer()
{
}

void GameplayScene::RestartLevel()
{
}

GameState GameplayScene::GetState()
{
	return states;
}

void GameplayScene::SetState(GameState states)
{
	this->states = states;
}