#include "Tile.h"

Tile::Tile(bool isLethal)
{
	this->isLethal = isLethal;
}
void Tile::Update(float dt)
{

}
Tile::Tile()
{
	isLethal = false;
}


void Tile::Render()
{
	for(ImageRenderer* render : renderer)
	{
		render->Render();
	}
}
