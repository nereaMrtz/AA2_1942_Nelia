#include "Object.h"

void Object::Update(float dt)
{
}

Transform Object::GetTransform()
{
    return transform;
}

Rigidbody Object::GetRigidbody()
{
    return physics;
}


void Object::SetPosition(Vector2 p)
{
    this->transform.position = p;
}

void Object::SetRotation(float r)
{
    this->transform.rotation = r;
}

void Object::SetScale(Vector2 s)
{
    this->transform.scale = s;
}

void Object::SetTransform(Transform t)
{
    this->transform = t;
}

void Object::SetVelocity(Vector2 v)
{
}

bool Object::IsPendingDestroy()
{
    return isPendingDestroy;
}

void Object::Destroy()
{
    isPendingDestroy = true;
}

void Object::OnCollisionEnter(Object* other)
{
}


