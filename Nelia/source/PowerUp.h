#pragma once
#include "GameObject.h"
#include "Player.h"

class PowerUp : public GameObject{
protected:
	Player* pj;
	Spawner* spawner;
	//ScoreManager* score;

public:
	PowerUp() = default;
	PowerUp(Player* pj);

	virtual void Update();
	virtual void OnCollisionEnter(Object* other);

};

