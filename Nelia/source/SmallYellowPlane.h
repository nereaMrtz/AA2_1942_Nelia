#pragma once
#include "EnemyPlane.h"

class SmallYellowPlane : public EnemyPlane {
protected:
	bool goesRight;
	bool isSpinning;

	void UpdateMovementPattern(float dt) override;

public:
	SmallYellowPlane();

	virtual void Update(float dt) override;
};

