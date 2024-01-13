#pragma once
#include <vector>
#include "AABB.h"
#include "Transform.h"

class Rigidbody
{
private:
	std::vector<AABB> colliders;
	Transform* transform;

	Vector2 velocity;
	float angularVelocity;

	Vector2 acceleration;
	float angularAcceleration;

	float linearDrag;
	float angularDrag;

public:
	Rigidbody(Transform* transform);
	Rigidbody() = default;
	~Rigidbody();

	void AddCollider(AABB collider);
	bool CheckCollision(const Rigidbody* other);
	bool CheckOverlappingPoint(Vector2 point);

	void Update(float dt);

	void AddForce(Vector2 force);
	void AddTorque(float amount);

	Vector2 GetVelocity();
	void SetVelocity(Vector2 vel);
	void SetLinearDrag(float linearD);
	void SetAngularDrag(float angularD);
};

