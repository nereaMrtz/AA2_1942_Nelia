#pragma once
#include <SDL.h>

#include "Transform.h"
#include "AABB.h"
#include "Vector2.h"

class Object {
private:
	bool isPendingDestroy;

public:
	Transform transform;
	//AABB boundingBox;  Clase rigidbody

	Object() = default;
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

	Transform GetTransform();
	//AABB GetBoundingBox();  Clase rigidbody


	void SetPosition(Vector2 p);
	void SetRotation(float r);
	void SetScale(Vector2 s);
	void SetTransform(Transform t);
	void SetVelocity(Vector2 v);

	bool IsPendingDestroy();

	//virtual void Destroy();
	//virtual void OnCollisionEnter(Object* other);

};
