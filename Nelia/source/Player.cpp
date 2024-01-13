#include "Player.h"

void Player::PlayRollAnimation()
{
}

Player::Player() : GameObject()
{

}

void Player::AddMovement(Vector2 dir)
{
	transform.position = transform.position + dir;
}

void Player::Update(float dt)
{
}

void Player::Render()
{
	for (auto element : renderer) {
		element->SetPosition(transform.position.x, transform.position.y);
		element->Render();
	}
}

void Player::Shoot()
{
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
