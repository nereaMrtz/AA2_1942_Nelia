#include "GameObject.h"



void GameObject::LoadTexture(SDL_Renderer* renderer, std::string path, bool isAnimated, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale)
{
	if (!isAnimated) {
		ImageRenderer* image = new ImageRenderer({ 255 }, 1, 0, targetRect, sourceRect, scale);
		image->Load(path.c_str());
		this->renderer.push_back(image);
	}
	else {
		AnimatedImageRenderer* animatedImage = new AnimatedImageRenderer(1, 0, targetRect, sourceRect, 60, true, 2, scale);
		animatedImage->Load(path.c_str());
		this->renderer.push_back(animatedImage);
	}
}

void GameObject::SetPosition(int x, int y)
{
	/*destinationRect.x = x;
	destinationRect.y = y;*/
}

void GameObject::Render()
{
	
}

//Renderer* GameObject::GetRenderer()
//{
//	return renderer;
//}
