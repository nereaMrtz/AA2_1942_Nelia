#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(Vector2 pjPos) : GameObject()
{
	LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 89, 68, 512, 512 }, { 2, 2 }, 6, 4, false, 5);
	ChangeSourcePosSize({ 0, 0 }, { 16, 32 }, 0);
	SetPosition(pjPos.x, pjPos.y - 26);
	physics = Rigidbody(&transform, Vector2(transform.position.x, transform.position.y), Vector2(16, 32));
}

void PlayerBullet::Update(float dt)
{
	SetPosition(transform.position.x, transform.position.y - dt * 100);
	physics.Update(dt);
}

void PlayerBullet::Render()
{
	for (auto element : renderer) {
        element->SetPosition(transform.position.x, transform.position.y);
        element->Render();
    }
}

void PlayerBullet::OnCollisionEnter(Object* other)
{
}
