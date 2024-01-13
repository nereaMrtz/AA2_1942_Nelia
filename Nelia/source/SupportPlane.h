#pragma once
#include "Player.h"
#include "GameObject.h"

class SupportPlane {
protected:
	bool isLeft;
	Player* player;
	bool isArriving;

public:
	SupportPlane(bool isLeft);

	virtual void Update(float dt); //override;
	virtual void Shoot(/*shoot*/);
	void OnCollisionEnter(Object* other); //override;
};

