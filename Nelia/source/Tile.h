#pragma once

#include "GameObject.h"

class Tile : public GameObject
{
private:
	bool isLethal;

public:
	Tile();
	Tile(bool isLethal);
	void Update() override;
	void Render() override;
};

