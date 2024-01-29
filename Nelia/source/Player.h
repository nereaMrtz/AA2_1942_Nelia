#pragma once
#include <iostream>
#include "GameObject.h"
#include "Spawner.h"
#include "SupportPlane.h"
#include "EnemyPlane.h"
#include "PlayerBullet.h"

class Player : public GameObject {
private:
	float fireTime;
	float lastFireTime;
	float bulletTimer;
	float time;

	bool isRolling;
	bool doubleFire;

	int currentAnim;
	int lives;

	Vector2 spawnPos;

	void PlayRollAnimation();

	std::vector<SupportPlane*> supportPlanes;
	std::vector<PlayerBullet*> bullets;

public:
	Player();
	void AddMovement(Vector2 dir);
	void Update(float dt) override;
	void Render() override;
	void Shoot();
	void Death();
	void PlayLandingAnimation();
	void PlayTakeOffAnimation();
	void EnableDoubleFire();
	void AddSupportPlanes();
	void OnCollisionEnter(Object* other) override;

	std::vector<PlayerBullet*>& GetBullets();
};

