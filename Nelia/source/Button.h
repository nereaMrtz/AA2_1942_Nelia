#pragma once

#include "GameObject.h"
#include "TextObject.h"

class Button : GameObject
{
private: 
	TextObject* text;

public:
	Button() = default;
	void Update() override;
	void Render() override;
};

