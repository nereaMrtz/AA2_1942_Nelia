#pragma once
#include "WaveType.h";
#include "MovementPattern.h";
#include "Player.h"
#include "SmallNormalPlane.h"
#include "SmallRedPlane.h"
#include "SmallYellowPlane.h"
#include "BigGreenPlane.h"

class Wave {
private:
	float startTime;
	float timer;

	WaveType type;
	MovementPattern movementPattern;

	int amount;

	std::vector<EnemyPlane*> spawnedPlanes;

	bool isFinished;

public:
	Wave(float startTime, WaveType type, MovementPattern movementPattern, int amount);

	std::vector<EnemyPlane*> SpawnPlanes(float dt);
	void Update(float dt);
	void Render();
	void Start();
	void IsFinished();
};

