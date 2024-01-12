#pragma once

#include "Object.h"
#include "TextRenderer.h"

class TextObject : public Object
{
private:
	TextRenderer renderer;

public:
	TextObject() = default;
	void Update(float dt) override;
	void Render() override;
};

