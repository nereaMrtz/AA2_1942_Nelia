#pragma once
#include<math.h>

class Vector2
{
public:
	int x;
	int y;

	Vector2();
	Vector2(float x, float y);

	Vector2 Normalize();

	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(const float other);

};

