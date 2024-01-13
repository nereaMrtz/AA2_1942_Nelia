#pragma once
#include "GameObject.h"

class PlayerBullet : public GameObject {
public:
	PlayerBullet(Vector2 pjPos);

	virtual void Update(float dt);
	void Render() override;
	void OnCollisionEnter(Object* other);
};

