#pragma once
#include "PowerUp.h"
class WhitePowerUp : public PowerUp {
public:
	WhitePowerUp(Player* pj, Spawner* spawner);

	void Update() override;
	void OnCollisionEnter(Object* other) override;
};

