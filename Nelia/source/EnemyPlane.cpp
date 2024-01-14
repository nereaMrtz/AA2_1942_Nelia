#include "EnemyPlane.h"

void EnemyPlane::UpdateMovementPattern(float dt)
{
}

void EnemyPlane::Shoot()
{
}

EnemyPlane::EnemyPlane()
{
	physics = Rigidbody(&transform, Vector2(transform.position.x, transform.position.y), Vector2(32, 24));
}

EnemyPlane::~EnemyPlane()
{
	//en caso de init spawner meter el delete
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
