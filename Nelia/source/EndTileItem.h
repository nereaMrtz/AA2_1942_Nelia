#pragma once

#include "GameObject.h"

class EndTileItem : GameObject
{
private:
	float duration;
	float currentDuration;
	bool isLethal;

public:
	EndTileItem(float duration, bool isLethal, std::string stringPath);

	void Update(float dt) override;
	void Render() override;
	bool isFinished();
};

