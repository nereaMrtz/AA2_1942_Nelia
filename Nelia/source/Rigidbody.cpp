#include "Rigidbody.h"

Rigidbody::Rigidbody(Transform* transform)
{
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::AddCollider(AABB collider)
{
	colliders.push_back(collider);
}

bool Rigidbody::CheckCollision(const Rigidbody* other)
{
	return false;
}

bool Rigidbody::CheckOverlappingPoint(Vector2 point)
{
	return false;
}

void Rigidbody::Update(float dt)
{
}

void Rigidbody::AddForce(Vector2 force)
{
	//La fuerza es la acceleracion y el torque?
}

void Rigidbody::AddTorque(float amount)
{
}

Vector2 Rigidbody::GetVelocity()
{
	return velocity;
}

void Rigidbody::SetVelocity(Vector2 vel)
{
	this->velocity = vel;
}

void Rigidbody::SetLinearDrag(float linearD)
{
	this->linearDrag = linearD;
}

void Rigidbody::SetAngularDrag(float angularD)
{
	this->angularDrag = angularD;

}
