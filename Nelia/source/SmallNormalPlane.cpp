#include "SmallNormalPlane.h"

void SmallNormalPlane::UpdateMovementPattern(float dt)
{
	
	switch (movementType)
	{
	case V:
		SetPosition(transform.position.x + dt * 200, transform.position.y + dt * 200);
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
	int random = rand() % 1;
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

	std::cout << random << std::endl;
}

void SmallNormalPlane::Update(float dt)
{
	UpdateMovementPattern(dt);
	//SetPosition(transform.position.x + dt * 150, transform.position.y + dt * 150);
	physics.Update(dt);
}
