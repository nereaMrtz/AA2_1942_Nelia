#pragma once
#include "PowerUp.h"

class GrayPowerUp : public PowerUp {
public:
	GrayPowerUp(Player* pj);
	GrayPowerUp(Player* pj, Spawner* spawner);

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};

