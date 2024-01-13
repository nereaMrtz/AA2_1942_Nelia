#pragma once
#include "EnemyPlane.h"

class BigGreenPlane : public EnemyPlane {
protected:
	bool isGoingUp;

	Vector2 targetPosition;

	void UpdateMovementPattern(float dt) override;

public:
	BigGreenPlane();
	virtual void Update(float dt) override;
};

