#include "SmallNormalPlane.h"

void SmallNormalPlane::UpdateMovementPattern(float dt)
{
	switch (movementType)
	{
	case V:
		SetPosition(transform.position.x + dt * 100, transform.position.y + dt * 100);
		//transform.position.x = -transform.position.x;
		break;
	case CURVE:

		break;
	case STRAIGHT:
		SetPosition(transform.position.x, transform.position.y+ dt * 200);
		break;
	default:
		break;
	}
}

SmallNormalPlane::SmallNormalPlane(MovementType mT)
{
	switch (mT)
	{
		case V:
			movementType = V;
		break;
		case STRAIGHT:
			movementType = STRAIGHT;
		break;
		case CURVE:
			movementType = CURVE;
		default:
		break;
	}

}

void SmallNormalPlane::Update(float dt)
{
	UpdateMovementPattern(dt);
	physics.Update(dt);
}
