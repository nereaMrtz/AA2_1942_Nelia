#include "Vector2.h"

Vector2::Vector2(): x(0), y(0) {

}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::Normalize() {
	double magnitude = sqrt(pow(x, 2) + pow(y, 2));

	x = x / magnitude;
	y = y / magnitude;

	Vector2 vector2(x, y);

	return vector2;
}