#pragma once
#include "GameObject.h"

class EnemyBullet {
public:
	EnemyBullet();

	virtual void Update(float dt); //override;
	void OnCollisionEnter(Object* other); //override;
};

