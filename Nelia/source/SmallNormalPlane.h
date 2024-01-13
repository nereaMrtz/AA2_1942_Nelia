#pragma once
#include "MovementType.h"
#include "EnemyPlane.h"

class SmallNormalPlane : public EnemyPlane{
protected:
	MovementType movementType;

	void UpdateMovementPattern(float dt) override;

public:
	SmallNormalPlane(MovementType mT);

	virtual void Update(float dt) override;
};

