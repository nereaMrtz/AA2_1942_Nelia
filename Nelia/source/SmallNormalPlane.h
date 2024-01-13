#pragma once
#include "MovementType.h"
#include "EnemyPlane.h"

#include <iostream>

class SmallNormalPlane : public EnemyPlane{
private:
	bool dir;

protected:
	MovementType movementType;

	void UpdateMovementPattern(float dt) override;

public:
	SmallNormalPlane(MovementType mT);

	virtual void Update(float dt) override;
};

