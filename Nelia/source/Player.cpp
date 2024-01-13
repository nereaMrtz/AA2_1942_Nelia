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
}

void Player::AddMovement(Vector2 dir)
{
	transform.position = transform.position + dir;
}

void Player::Update(float dt)
{
	if (IM->CheckKeyState(SDLK_UP, PRESSED))
		AddMovement({ 0, -50 * dt });
	if (IM->CheckKeyState(SDLK_DOWN, PRESSED))
		AddMovement({ 0, 50 * dt });
	if (IM->CheckKeyState(SDLK_LEFT, PRESSED)) {
		currentAnim = 1;
		AddMovement({ -50 * dt,0 });
	}
	else {
		renderer[1]->Reset();
	}
	if (IM->CheckKeyState(SDLK_RIGHT, PRESSED)) {
		currentAnim = 2;
		AddMovement({ 50 * dt, 0 });
	}
	else {
		renderer[2]->Reset();
	}  

	if (IM->CheckKeyState(SDLK_SPACE, PRESSED)) {
		Shoot();
	}

	if (bullet != nullptr)
		bullet->Update(dt);
}

void Player::Render()
{
	renderer[currentAnim]->SetPosition(transform.position.x, transform.position.y);
	renderer[currentAnim]->Update();
	renderer[currentAnim]->Render();

	if(bullet!= nullptr)
		bullet->Render();
}

void Player::Shoot()
{
	bullet = new PlayerBullet;
	bullet->SetPosition(this->GetTransform().position.x, this->GetTransform().position.y - 26);
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
