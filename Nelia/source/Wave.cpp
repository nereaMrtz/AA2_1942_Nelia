#include "Wave.h"

Wave::Wave(float startTime, WaveType type, MovementPattern movementPattern, int amount)
{
	this->startTime = startTime;
	this->type = type;
	this->movementPattern = movementPattern;
	this->amount = amount;

	timer = 0;
	spawn = true; 

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
}

std::vector<EnemyPlane*>& Wave::Update(float dt)
{	
	timer += dt;
	if (timer < startTime) {
		std::vector<EnemyPlane*> empty;
		return empty;
	}

	for (auto& plane : spawnedPlanes) {
		plane->Update(dt);
	}

	//handle destroy
	for (int i = 0; i < spawnedPlanes.size(); i++)
	{
		if (spawnedPlanes[i]->IsPendingDestroy()) 
		{
			delete spawnedPlanes[i];	//clear memory
			spawnedPlanes.erase(spawnedPlanes.begin() + i);
			i = 0;
		}

	}

	return spawnedPlanes;
}

void Wave::Render()
{
	if (timer < startTime) return;

	for (auto& plane : spawnedPlanes) {
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
