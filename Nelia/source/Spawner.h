#pragma once

#include "GameObject.h"

class Spawner : GameObject
{
private:
	float maxSpawnTime;
	float minSpawnTime;
	float elapsedTime;
	Vector2 startPosition;
	Vector2 startVelocity;

public:
	//Spawner<ObjectType>();
	//ObjectType* Update();
};

