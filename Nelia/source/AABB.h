#pragma once
#include <SDL.h>

#include "Vector2.h"

class AABB {
protected:
	Vector2 topLeft;
	Vector2 size;

public:
	AABB();
	AABB(Vector2 topLeft, Vector2 size);

	bool CheckOverlappingAABB(const AABB* other);
	bool CheckOverlappingPoint(Vector2 point);

	Vector2 GetTopLeft();
	Vector2 GetSize();

	void SetTopLeft(Vector2 topLeft);
	void SetSize(Vector2 size);
};
