#pragma once
#include <cstdlib>
#include "Spawner.h"
#include "GameObject.h"

class EnemyPlane : public GameObject {
protected:
	int health;
	int score;
	int movementStage;

	Vector2 initPos;

	float movementTime;

	Spawner* spawner;

	virtual void UpdateMovementPattern(float dt) = 0;
	virtual void Shoot();

public:
	EnemyPlane();
	EnemyPlane(int health, int score, Spawner* spawner);
	
	virtual void Update(float dt);
	void Render() override;
	virtual void OnCollisionEnter(Object* other);
};

