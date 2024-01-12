#include "Object.h"

Transform Object::GetTransform()
{
    return transform;
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


