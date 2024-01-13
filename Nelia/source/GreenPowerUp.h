#pragma once
#include "PowerUp.h"

class GreenPowerUp : public PowerUp {
public:
	GreenPowerUp(Player* pj, Spawner* spawner);

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};

