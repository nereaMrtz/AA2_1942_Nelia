#pragma once
#include <SDL.h>

#include "Transform.h"
#include "AABB.h"
#include "Vector2.h"
#include "Rigidbody.h"

class Object {
private:
	bool isPendingDestroy;

public:
	Transform transform;
	Rigidbody physics;

	Object() = default;
	virtual void Update(float dt);
	virtual void Render() = 0;

	Transform GetTransform();
	Rigidbody GetRigidbody();


	void SetPosition(Vector2 p);
	void SetRotation(float r);
	void SetScale(Vector2 s);
	void SetTransform(Transform t);
	void SetVelocity(Vector2 v);
	void SetRigidboy(Rigidbody rig);

	bool IsPendingDestroy();

	virtual void Destroy();
	virtual void OnCollisionEnter(Object* other);
};
