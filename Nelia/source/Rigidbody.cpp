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
    /*
    //Top right corner
    bool collision = (topLeft.x < other->topLeft.x && other->topLeft.x < (topLeft.x + size.x)) && (topLeft.y < other->topLeft.y && other->topLeft.y < (topLeft.y + size.y));
    if (collision)
        return true;

    //Top left corner
    collision = (topLeft.x < (other->topLeft.x + other->size.x)) && (other->topLeft.x + other->size.x) < (topLeft.x + size.x) && (topLeft.y < other->topLeft.y && other->topLeft.y < (topLeft.y + size.y));
    if (collision)
        return true;

    //Bottom right corner
    collision = (topLeft.x < other->topLeft.x && other->topLeft.x < (topLeft.x + size.x)) && (topLeft.y < (other->topLeft.y + other->size.y) && (other->topLeft.y + other->size.y) < (topLeft.y + size.y));
    if (collision)
        return true;

    //Bottom left corner
    collision = (topLeft.x < (other->topLeft.x + other->size.x) && (other->topLeft.x + other->size.x) < (topLeft.x + size.x)) && (topLeft.y < (other->topLeft.y + other->size.y) && (other->topLeft.y + other->size.y) < (topLeft.y + size.y));
    if (collision)
        return true;*/

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
