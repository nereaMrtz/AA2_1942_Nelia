#pragma once
#include "MovementPattern.h"
#include "EnemyPlane.h"

#include <iostream>

class SmallNormalPlane : public EnemyPlane{
private:
	bool dir;

protected:
	MovementPattern movementType;

	void UpdateMovementPattern(float dt) override;

public:
	SmallNormalPlane(MovementPattern mT);

	virtual void Update(float dt) override;
	void SpawnPlane(std::vector<SmallNormalPlane*>& normalPlane, int amount);
};

