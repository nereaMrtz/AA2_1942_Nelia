#pragma once
#include "GameObject.h"

class SupportPlane : GameObject {
protected:
	bool isLeft;
	//Player* player;
	bool isArriving;

public:
	SupportPlane(bool isLeft);

	virtual void Update(float dt);
	virtual void Shoot();
	void OnCollisionEnter(Object* other);
};

