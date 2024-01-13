#pragma once
#include "WaveType.h";
#include "MovementPattern.h";
#include "Player.h"

class Wave {
private:
	float startTime;

	WaveType type;
	MovementPattern movementPattern;

	int amount;

	std::vector<EnemyPlane> spwnedPlanes;

	bool isFinished;

public:
	Wave(float startTime, WaveType type, MovementPattern movementPattern, int amount);

	void Update(float dt, const Player& pj, Spawner* spawner);
	void Start();
	void IsFinished();
};

