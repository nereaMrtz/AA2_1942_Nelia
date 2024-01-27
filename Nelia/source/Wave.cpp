#include "Wave.h"

Wave::Wave(float startTime, WaveType type, MovementPattern movementPattern, int amount)
{
	this->startTime = startTime;
	this->type = type;
	this->movementPattern = movementPattern;
	this->amount = amount;

	timer = 0;
	spawn = true; 
}

std::vector<EnemyPlane*>& Wave::SpawnPlanes(float dt)
{
	timer += dt;

	if (timer >= startTime && spawn) {
		for (int i = 0; i < amount; i++) {

			switch (type)
			{
			case WaveType::normal: {
				SmallNormalPlane* newPlane = new SmallNormalPlane(movementPattern);
				spawnedPlanes.push_back(newPlane);
			}break;
			case WaveType::medium_yellow: {
				SmallNormalPlane* newPlane = new SmallNormalPlane(movementPattern);
				spawnedPlanes.push_back(newPlane);
			}break;
			case WaveType::big_green: {
				SmallNormalPlane* newPlane = new SmallNormalPlane(movementPattern);
				spawnedPlanes.push_back(newPlane);
			}break;
			case WaveType::small_red: {
				SmallNormalPlane* newPlane = new SmallNormalPlane(movementPattern);
				spawnedPlanes.push_back(newPlane);
			}break;
			default:
				std::cout << "t" << std::endl;
				break;
			}

		}
		timer = 0;
		spawn = false;
	}
	

	return spawnedPlanes;
}

void Wave::Update(float dt)
{
	for (auto plane : spawnedPlanes) {
		plane->Update(dt);
	}
}

void Wave::Render()
{
	for (auto plane : spawnedPlanes) {
		plane->Render();
	}
}

void Wave::Start()
{
}

void Wave::IsFinished()
{
}

float Wave::GetStartTime()
{
	return startTime;
}
