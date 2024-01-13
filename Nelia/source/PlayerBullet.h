#pragma once
#include "GameObject.h"

class PlayerBullet
{
public:
	PlayerBullet();

	virtual void Update(float dt); //override;
	void OnCollisionEnter(Object* other); //override;

};

