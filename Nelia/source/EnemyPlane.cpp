#include "EnemyPlane.h"

void EnemyPlane::UpdateMovementPattern(float dt)
{
}

void EnemyPlane::Shoot()
{
}

EnemyPlane::EnemyPlane()
{
	//physics = Rigidbody(&transform, Vector2(transform.position.x - 12, transform.position.y - 8), Vector2(32, 24));
}

EnemyPlane::EnemyPlane(int health, int score, Spawner* spawner)
{
}

void EnemyPlane::Update(float dt)
{
}

void EnemyPlane::Render()
{
	for (auto element : renderer) {
		element->SetPosition(transform.position.x, transform.position.y);
		element->Render();
	}
}

void EnemyPlane::OnCollisionEnter(Object* other)
{
}
