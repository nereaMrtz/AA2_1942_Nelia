#pragma once
#include <vector>
#include "AABB.h"
#include "Transform.h"

class Rigidbody
{
private:
	AABB* collider;
	Transform* transform;

	Vector2 velocity;
	float angularVelocity;

	Vector2 acceleration;
	float angularAcceleration;

	float linearDrag;
	float angularDrag;

public:
	Rigidbody(Transform* trans, Vector2 topLeft, Vector2 size);
	Rigidbody() = default;
	~Rigidbody();

	void AddCollider(AABB* collider);
	bool CheckCollision( AABB* other);
	bool CheckOverlappingPoint(Vector2 point);

	void Update(float dt);

	void AddForce(Vector2 force);
	void AddTorque(float amount);

	Vector2 GetVelocity();
	void SetVelocity(Vector2 vel);
	void SetLinearDrag(float linearD);
	void SetAngularDrag(float angularD);

	AABB* GetCollider();
};

