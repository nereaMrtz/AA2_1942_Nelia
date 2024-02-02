#include "Player.h"
#include "InputManager.h"

void Player::PlayRollAnimation()
{
}

Player::Player() : GameObject()
{
	currentAnim = 0;
	lives = 3;
	spawnPos = Vector2(RM->windowWidth / 2, RM->windowHeight -100);

	LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 2, 2 }, 2, 1, false, 2);
	ChangeSourcePosSize({ 0,0 }, { 32,24 }, 0); //0: Idle anim
	LoadTexture(RM->GetRenderer(), "resources/sprites.png", true, { 0,0, 512, 512 }, { 64,0, 512, 512 }, { 2, 2 }, 3, 1, false, 1);
	ChangeSourcePosSize({ 0,0 }, { 32,24 }, 1); //1: Left anim
	LoadTexture(RM->GetRenderer(), "resources/sprites.png", true, { 0,0, 512, 512 }, { 32,0, 512, 512 }, { 2, 2 }, 3, 1, false, 1);
	ChangeSourcePosSize({ 0,0 }, { 32,24 }, 2); //2: Right anim	

	//death anim

	SetPosition(spawnPos.x, spawnPos.y);

	physics = Rigidbody(&transform, Vector2(transform.position.x, transform.position.y), Vector2(32,24));

	timer = 0.f;
	dead = false;
}

void Player::AddMovement(Vector2 dir)
{
	transform.position = transform.position + dir;
}

void Player::Update(float dt)
{
	// UP
	if (IM->CheckKeyState(SDLK_UP, PRESSED) && transform.position.y >= 11) {
		AddMovement({ 0, -100 * dt });
	}

	// Down
	if (IM->CheckKeyState(SDLK_DOWN, PRESSED) && transform.position.y <= RM->windowHeight - 22)
		AddMovement({ 0, 100 * dt });

	// Left
	if (IM->CheckKeyState(SDLK_LEFT, PRESSED) && transform.position.x >= 22) {
		currentAnim = 1;
		AddMovement({ -100 * dt,0 });
	}
	else {
		renderer[1]->Reset();
	}

	// Right
	if (IM->CheckKeyState(SDLK_RIGHT, PRESSED) && transform.position.x <= RM->windowWidth - 32) {
		currentAnim = 2;
		AddMovement({ 100 * dt, 0 });
	}
	else {
		renderer[2]->Reset();
	}  

	if (!bullets.empty()) {
		for (auto bullet : bullets) {
			bullet->Update(dt);
		}
	}

	if (bulletTimer >= 1 && IM->CheckKeyState(SDLK_SPACE, PRESSED)) {
		bulletTimer = 0;

		Shoot();
	}

	physics.Update(dt);

	bulletTimer += TM->GetDtSec();

	if (resetTimer) {
		timer = 0;
		resetTimer = false;
	}

	if (lives == 0) {
		dead = true;
	}

	//Player Damage
	if (damage) {

		// play death animation
		SDL_Delay(1000);
		if (canTakeLife) {
			lives--;
			std::cout << "te quito vida" << std::endl;
			canTakeLife = false;
		}

		SDL_Delay(3000);
		//screen turns blue
		SDL_SetRenderDrawColor(RM->GetRenderer(), 255, 0, 0, 255);
		SDL_Delay(3000);
		SetPosition(spawnPos.x, spawnPos.y);
		std::cout << "pium pium" << std::endl;
		damage = false;
		
	}
	if (IM->CheckKeyState(SDLK_c, PRESSED)) {
		lives = 0;
		std::cout << "morisionado" << std::endl;
	}
	timer += dt;
}

void Player::Render()
{
	renderer[currentAnim]->SetPosition(transform.position.x, transform.position.y);
	renderer[currentAnim]->Update();
	renderer[currentAnim]->Render();

	if (!bullets.empty()) {
		for (auto bullet : bullets) {
			bullet->Render();
		}
	}
}

void Player::Shoot()
{
	PlayerBullet* bulletAux = new PlayerBullet(transform.position);
	AM->PlayClip("pium", 0);
	bullets.push_back(bulletAux);
}

void Player::Death()
{
	ResetTimer();
	damage = true;
	canTakeLife = true;
}

void Player::PlayLandingAnimation()
{
}

void Player::PlayTakeOffAnimation()
{
}

void Player::EnableDoubleFire()
{
}

void Player::AddSupportPlanes()
{
}

void Player::OnCollisionEnter(Object* other)
{
}

void Player::ResetTimer()
{
	resetTimer = true;
}

bool Player::isDead()
{
	return dead;
}

std::vector<PlayerBullet*>& Player::GetBullets()
{
	return bullets;
}
