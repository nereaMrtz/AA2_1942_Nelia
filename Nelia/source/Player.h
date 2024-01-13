#pragma once
#include "GameObject.h"
#include "Spawner.h"
#include "SupportPlane.h"
#include "EnemyPlane.h"

class Player : public GameObject {
private:
	bool isRolling;
	float fireTime;
	float lastFireTime;
	bool doubleFire;
	std::vector<SupportPlane*> supportPlanes;
	void PlayRollAnimation();
	int currentAnim;

public:
	Player();
	void AddMovement(Vector2 dir);
	void Update(float dt) override;
	void Render() override;
	void Shoot();
	void PlayDeathAnimation() /*override*/;
	void PlayLandingAnimation();
	void PlayTakeOffAnimation();
	void EnableDoubleFire();
	void AddSupportPlanes();
	void OnCollisionEnter(Object* other) override;
};

