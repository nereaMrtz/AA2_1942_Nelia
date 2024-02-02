#include "SmallNormalPlane.h"

void SmallNormalPlane::UpdateMovementPattern(float dt)
{
	switch (movementType)
	{
	case MovementPattern::V:
		if (dir) {
			SetPosition(transform.position.x + dt * 300, transform.position.y + dt * 300);
		}
		else {
			SetPosition(-transform.position.x + dt * 5, transform.position.y + dt * 300);
		}
		break;
	case MovementPattern::O:
		std::cout << transform.position.y << std::endl;
		if (transform.position.y > 200)
			SetPosition(transform.position.x + dt * 300, transform.position.y + dt * 300);
		SetPosition(transform.position.x, transform.position.y + dt * 300);
		break;
	case MovementPattern::I:
		SetPosition(transform.position.x, transform.position.y + dt * 300);
		break;
	default:
		break;
	}

}

SmallNormalPlane::SmallNormalPlane(MovementPattern mT) : EnemyPlane()
{
	movementType = mT;

	int random = rand() % 5 + 2;

	LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,160, 512, 512 }, { 2, 2 }, 0, 0, false, 0);
	ChangeSourcePosSize({ 0,0 }, { 24,16 }, 0);
	SetPosition(RM->windowWidth / random, -RM->windowHeight);

	int randomDir = rand() % 2;
	//dir = randomDir;
	dir = true;
	std::cout << randomDir << std::endl;

}

void SmallNormalPlane::Update(float dt)
{
	UpdateMovementPattern(dt);
	physics.Update(dt);
}


