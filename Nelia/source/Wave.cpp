#include "Wave.h"

Wave::Wave(float startTime, WaveType type, MovementPattern movementPattern, int amount)
{
	this->startTime = startTime;
	this->type = type;
	this->movementPattern = movementPattern;
	this->amount = amount;

	timer = 0;
}

void Wave::Update(float dt)
{
	timer += dt;


	if (timer >= startTime) {
		for (int i = 0; i < amount; i++) {
			switch (type)
			{
			case WaveType::normal:
				spawnedPlanes.push_back(new SmallNormalPlane(movementPattern));
				break;
			case WaveType::medium_yellow:
				break;
			case WaveType::big_green:
				break;
			case WaveType::small_red:
				break;
			default:
				break;
			}
		}
	}
}

void Wave::Start()
{
}

void Wave::IsFinished()
{
}
