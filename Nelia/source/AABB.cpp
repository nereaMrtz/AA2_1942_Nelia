#include "AABB.h"

AABB::AABB()
{
}

AABB::AABB(Vector2 topLeft, Vector2 size)
{
	this->topLeft = topLeft;
	this->size = size;
}

bool AABB::CheckOverlappingAABB(const AABB* other)
{
	//Condicion de si se chocan
	if ((topLeft.Normalize().x > other->topLeft.x) && (topLeft.Normalize().y > other->topLeft.y))
		return true;

	return false;
	
	// CIRCULOS
	// 1- Calcular el vector entre topLeft y other->topLeft
	// 2- Calcular el módulo de ese vector
	// 3- Comparación: if(modulo <= radio topLeft) --> hay colisión
}

bool AABB::CheckOverlappingPoint(Vector2 point)
{
	// Condicion de si ese punto esta dentro de la boundingBox
	if ((topLeft.Normalize().x <= point.x) && (topLeft.Normalize().y <= point.y))
		return true;

	return false;
}

Vector2 AABB::GetTopLeft()
{
	return topLeft;
}

Vector2 AABB::GetSize()
{
	return size;
}

void AABB::SetTopLeft(Vector2 topLeft)
{
	this->topLeft = topLeft;
}

void AABB::SetSize(Vector2 size)
{
	this->size = size;
}