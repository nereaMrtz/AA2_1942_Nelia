#include "GameplayScene.h"

GameplayScene::GameplayScene()
{
	states = GameState::GAMEPLAY;
	background = Tile(false);
	player = new Player();

	background.LoadTexture(RM->GetRenderer(), "resources/WaterBackground.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 10, 10 }, 0, 0, false, 0);

	LevelLoader loader;
	waves = loader.LoadWaves("resources/stage_0.xml", levelTime);
	HM->LoadScores("resources/ranking.xml");
	//loader.LoadRanking("resources/ranking.xml");

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
					score.AddScore(10);

					if (player->isDead()) {
						states = DEATH;
						AM->PlayClip("gameover", 0);
					}
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
						score.AddScore(50);

						AM->PlayClip("colisionPlayerEnemigo", 0);
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
		std::cout << score.GetScore() << std::endl;

		if (IM->CheckKeyState(SDLK_ESCAPE, PRESSED)) {
			states = PAUSED;
			break;
		}

		hud.UpdateScore(score.GetScore());
		break;
	case GameState::PAUSED:
		SM->SetScene("Pause Menu");
		std::cout << "PAUSADO";
		states = GAMEPLAY;
		break;

	case GameState::FINISH_STAGE:
		break;

	case GameState::DEATH:
		SM->SetScene("Game Over");

		RestartLevel();
		RestartTimer();
		states = GAMEPLAY;
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

	hud.Render();
}

void GameplayScene::OnEnter()
{
	LevelLoader loader;
	waves = loader.LoadWaves("resources/stage_0.xml", levelTime); 
	
	AM->PlayMusic("musicaFondo");
}


void GameplayScene::OnExit()
{
	AM->MuteAudio();
}


void GameplayScene::RestartTimer()
{
	timer = 0;
	spawnerTime = 0;
	spawn = false;
}

void GameplayScene::RestartLevel()
{
	delete player;

	player = new Player();

	score.AddScore(-score.GetScore());

	HM->LoadScores("resources/ranking.xml");
}

GameState GameplayScene::GetState()
{
	return states;
}

void GameplayScene::SetState(GameState states)
{
	this->states = states;
}