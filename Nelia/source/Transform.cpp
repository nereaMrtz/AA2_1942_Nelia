#include "Transform.h"

Transform::Transform()
{
}

Transform::Transform(Vector2 position, float rotation, Vector2 scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

}
