#pragma once
#include <iostream>
#include "GameObject.h"
#include "Spawner.h"
#include "SupportPlane.h"
#include "EnemyPlane.h"
#include "PlayerBullet.h"
#include "AudioManager.h"

class Player : public GameObject {
private:
	float fireTime;
	float lastFireTime;
	float bulletTimer;
	float timer;

	bool isRolling;
	bool doubleFire;
	bool damage;
	bool canTakeLife;
	bool resetTimer;
	bool dead;

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

	void ResetTimer();
	bool isDead();

	std::vector<PlayerBullet*>& GetBullets();
};

