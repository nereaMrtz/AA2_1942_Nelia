#pragma once
#include "Spawner.h"
#include "GameObject.h"

class EnemyPlane {
protected:
	int health;
	int score;
	int movementStage;

	float movementTime;

	Spawner* spawner;

	virtual void UpdateMovementPattern(float dt) = 0;
	virtual void Shoot();

public:
	EnemyPlane();
	EnemyPlane(int health, int score, Spawner* spawner);
	
	virtual void Update(float dt);
	virtual void OnCollisionEnter(Object* other);
};

