#include "SmallNormalPlane.h"

void SmallNormalPlane::UpdateMovementPattern(float dt)
{
	switch (movementType)
	{
	case MovementPattern::V:
		//SetPosition(transform.position.x + dt * 100, transform.position.y + dt * 100);
		transform.position.x += dt * 100;
		transform.position.y += dt * 100;
		SetPosition(transform.position.x, transform.position.y);
		break;
	case MovementPattern::O:

		break;
	case MovementPattern::I:
		SetPosition(transform.position.x, transform.position.y+ dt * 200);
		break;
	default:
		break;
	}
}

SmallNormalPlane::SmallNormalPlane(MovementPattern mT) : EnemyPlane()
{
	
	switch (mT)
	{
	case MovementPattern::V:
		movementType = MovementPattern::V;
		break;
	case MovementPattern::O:
		movementType = MovementPattern::O;
		break;
	case MovementPattern::I:
		movementType = MovementPattern::I;
		break;
	default:
		break;
	}

	int random = rand() % 5 + 2;

	LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,160, 512, 512 }, { 1, 1 }, 0, 0, false, 0);
	ChangeSourcePosSize({ 0,0 }, { 24,16 }, 0);
	SetPosition(RM->windowWidth / random, RM->windowHeight / 6);
	//std::cout << random <<" "<< random << std::endl;
	//normalPlane.push_back(enemy);

}

void SmallNormalPlane::Update(float dt)
{
	UpdateMovementPattern(dt);
	physics.Update(dt);
}


