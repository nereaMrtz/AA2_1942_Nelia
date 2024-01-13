#pragma once

#include "GameObject.h"
#include <queue>

class Spawner : GameObject
{
private:
	/*float maxSpawnTime;
	float minSpawnTime;
	float elapsedTime;
	Vector2 startVelocity;*/
	std::queue<Object*> objectsToSpawn;

public:
	//Spawner<ObjectType>();
	//ObjectType* Update();

	Spawner();

	void SpawnObject(Object* obj);
	void ClearSpawnDequeue();

	bool HasObjectsToSpawn();

	Object* DequeueObjectToSpawn();
};

