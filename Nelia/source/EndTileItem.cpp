#include "EndTileItem.h"

EndTileItem::EndTileItem(float duration, bool isLethal, std::string stringPath)
{
	this->duration = duration;
	this->isLethal = isLethal;
}

void EndTileItem::Update()
{
}

void EndTileItem::Render()
{
}

bool EndTileItem::isFinished()
{
	return false;
}
