#pragma once
#include "GameObject.h"

class PlayerBullet : public GameObject {
public:
	PlayerBullet();

	virtual void Update(float dt);
	void Render() override;
	void OnCollisionEnter(Object* other);
};

