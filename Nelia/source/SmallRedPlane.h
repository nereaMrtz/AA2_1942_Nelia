#pragma once
#include"EnemyPlane.h"

class SmallRedPlane : public EnemyPlane {
protected:
	bool goesRight;
	bool isSpinning;

	void UpdateMovementPattern(float dt) override;

public:
	SmallRedPlane();

	virtual void Update(float dt) override;
};

