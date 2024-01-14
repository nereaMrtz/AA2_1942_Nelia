#include "Player.h"
#include "InputManager.h"

void Player::PlayRollAnimation()
{
}

Player::Player() : GameObject()
{
	currentAnim = 0;
	LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 2, 2 }, 2, 1, false, 2);
	ChangeSourcePosSize({ 0,0 }, { 32,24 }, 0); //0: Idle anim
	LoadTexture(RM->GetRenderer(), "resources/sprites.png", true, { 0,0, 512, 512 }, { 64,0, 512, 512 }, { 2, 2 }, 3, 1, false, 1);
	ChangeSourcePosSize({ 0,0 }, { 32,24 }, 1); //1: Left anim
	LoadTexture(RM->GetRenderer(), "resources/sprites.png", true, { 0,0, 512, 512 }, { 32,0, 512, 512 }, { 2, 2 }, 3, 1, false, 1);
	ChangeSourcePosSize({ 0,0 }, { 32,24 }, 2); //2: Right anim	

	SetPosition(RM->windowWidth / 2, RM->windowHeight / 2);

	physics = Rigidbody(&transform, Vector2(transform.position.x, transform.position.y), Vector2(32,24));
}

void Player::AddMovement(Vector2 dir)
{
	transform.position = transform.position + dir;
}

void Player::Update(float dt)
{
	// UP
	if (IM->CheckKeyState(SDLK_UP, PRESSED) && transform.position.y >= 11) {
		AddMovement({ 0, -80 * dt });
	}

	// Down
	if (IM->CheckKeyState(SDLK_DOWN, PRESSED) && transform.position.y <= RM->windowHeight - 22)
		AddMovement({ 0, 80 * dt });

	// Left
	if (IM->CheckKeyState(SDLK_LEFT, PRESSED) && transform.position.x >= 22) {
		currentAnim = 1;
		AddMovement({ -80 * dt,0 });
	}
	else {
		renderer[1]->Reset();
	}

	// Right
	if (IM->CheckKeyState(SDLK_RIGHT, PRESSED) && transform.position.x <= RM->windowWidth - 32) {
		currentAnim = 2;
		AddMovement({ 80 * dt, 0 });
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

	bullets.push_back(bulletAux);
}

void Player::PlayDeathAnimation()
{
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

std::vector<PlayerBullet*>& Player::GetBullets()
{
	return bullets;
}
