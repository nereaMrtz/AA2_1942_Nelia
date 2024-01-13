#include "EnemyPlane.h"

void EnemyPlane::UpdateMovementPattern(float dt)
{
}

void EnemyPlane::Shoot()
{
}

EnemyPlane::EnemyPlane()
{
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
