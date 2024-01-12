#pragma once

#include "GameObject.h"
#include "TextObject.h"

class Button : GameObject
{
private: 
	TextObject* text;

public:
	Button() = default;
	void Update(float dt) override;
	void Render() override;
};

