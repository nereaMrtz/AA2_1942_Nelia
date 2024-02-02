#pragma once
#include "MovementPattern.h"
#include "EnemyPlane.h"

#include <iostream>


class SmallNormalPlane : public EnemyPlane{
private:
	bool dir;

	const float speed = 300;

protected:
	MovementPattern movementType;

	void UpdateMovementPattern(float dt) override;

public:
	SmallNormalPlane(MovementPattern mT);

	void Update(float dt) override;
};

