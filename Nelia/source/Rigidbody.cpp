#include "Rigidbody.h"

Rigidbody::Rigidbody(Transform* trans, Vector2 topLeft, Vector2 size)
{
    transform = trans;
    collider = new AABB(topLeft, size);
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::AddCollider(AABB* collider)
{
	//colliders.push_back(collider);
}

bool Rigidbody::CheckCollision(AABB* other)
{
   /*
    //Top right corner
    bool collision = (collider->GetTopLeft().x < other->GetTopLeft().x && other->GetTopLeft().x < (collider->GetTopLeft().x + collider->GetSize().x)) && (collider->GetTopLeft().y < other->GetTopLeft().y && other->GetTopLeft().y < (collider->GetTopLeft().y + collider->GetSize().y));
    if (collision)
        return true;

    //Top left corner
    collision = (collider->GetTopLeft().x < (other->GetTopLeft().x + other->GetSize().x)) && (other->GetTopLeft().x + other->GetSize().x) < (collider->GetTopLeft().x + collider->GetSize().x) && (collider->GetTopLeft().y < other->GetTopLeft().y && other->GetTopLeft().y < (collider->GetTopLeft().y + collider->GetSize().y));
    if (collision)
        return true;

    //Bottom right corner
    collision = (collider->GetTopLeft().x < other->GetTopLeft().x && other->GetTopLeft().x < (collider->GetTopLeft().x + collider->GetSize().x)) && (collider->GetTopLeft().y < (other->GetTopLeft().y + other->GetSize().y) && (other->GetTopLeft().y + other->GetSize().y) < (collider->GetTopLeft().y + collider->GetSize().y));
    if (collision)
        return true;

    //Bottom left corner
    collision = (collider->GetTopLeft().x < (other->GetTopLeft().x + other->GetSize().x) && (other->GetTopLeft().x + other->GetSize().x) < (collider->GetTopLeft().x + collider->GetSize().x)) && (collider->GetTopLeft().y < (other->GetTopLeft().y + other->GetSize().y) && (other->GetTopLeft().y + other->GetSize().y) < (collider->GetTopLeft().y + collider->GetSize().y));
    if (collision)
        return true;

        */
    //Top right
    
    //esquina up derecha
   // collider->GetTopLeft().x + collider->GetSize().x;
    // esquina inf derecha
   // collider->GetTopLeft() + collider->GetSize();
    //abajo izqu
   // collider->GetTopLeft().y + collider->GetSize().y;


    //bool collision = (collider->GetTopLeft().x + collider->GetSize().x > other->GetTopLeft().y && collider->GetTopLeft().x + collider->GetSize().x > other->GetTopLeft().y + other->GetSize().y);
      //  if (collision) {
      //      return true;
      //  }

       // bool touching([objectType] A, [objectType] B) {
            return  collider->GetTopLeft().x + collider->GetSize().x > other->GetTopLeft().x &&
               collider->GetTopLeft().x < other->GetTopLeft().x + other->GetSize().x &&
                collider->GetTopLeft().y + collider->GetSize().y > other->GetTopLeft().y &&
                collider->GetTopLeft().y < other->GetTopLeft().y + other->GetSize().y;
       // }

   // return false;
    
}

bool Rigidbody::CheckOverlappingPoint(Vector2 point)
{
	return false;
}

void Rigidbody::Update(float dt)
{
    collider->SetTopLeft(transform->position);
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

AABB* Rigidbody::GetCollider()
{
    return collider;
}
