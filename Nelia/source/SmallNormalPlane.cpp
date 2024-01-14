#include "SmallNormalPlane.h"

void SmallNormalPlane::UpdateMovementPattern(float dt)
{
	switch (patternType)
	{
	case V:
		SetPosition(transform.position.x + dt * 100, transform.position.y + dt * 100);
		//transform.position.x = -transform.position.x;
		break;
	case O:

		break;
	case I:
		SetPosition(transform.position.x, transform.position.y+ dt * 200);
		break;
	default:
		break;
	}
}

SmallNormalPlane::SmallNormalPlane(MovementPattern mT)
{
	

	switch (mT)
	{
		case V:
			movementType = V;
		break;
		case I:
			movementType = STRAIGHT;
		break;
		case O:
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

void SmallNormalPlane::SpawnPlane(std::vector<SmallNormalPlane*>& normalPlane, int amount)
{
	// Amount 
	for (int i = 0; i < amount; i++)
	{
		int random = rand() % 5 + 2;

		auto enemy = new SmallNormalPlane(V);
		enemy->LoadTexture(RM->GetRenderer(), "resources/sprites.png", false, { 0,0, 512, 512 }, { 0,160, 512, 512 }, { 1, 1 }, 0, 0, false, 0);
		enemy->ChangeSourcePosSize({ 0,0 }, { 24,16 }, 0);
		enemy->SetPosition(RM->windowWidth / random, RM->windowHeight / 6);
		//std::cout << random <<" "<< random << std::endl;
		normalPlane.push_back(enemy);

	}
}
