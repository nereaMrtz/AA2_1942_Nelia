#pragma once
#include "GameObject.h"
#include "Spawner.h"

class Player : GameObject
{
private:
	bool isRolling;
	float fireTime;
	float lastFireTime;
	bool doubleFire;
	//std::vector<SupportPlane> supportPlanes;
	Spawner* spawner;

	void PlayRollAnimation();

public:
	Player(Spawner* spawner);
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

