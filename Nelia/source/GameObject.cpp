#include "GameObject.h"

void GameObject::LoadTexture(SDL_Renderer* renderer, std::string path, bool isAnimated, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale, int rows, int cols)
{
	if (!isAnimated) {
		ImageRenderer* image = new ImageRenderer({ 255 }, 1, 0, targetRect, sourceRect, scale);
		image->Load(path.c_str());
		this->renderer.push_back(image);
	}
	else {
		AnimatedImageRenderer* animatedImage = new AnimatedImageRenderer(1, 0, targetRect, sourceRect, 60, true, 2, scale, rows, cols);
		animatedImage->Load(path.c_str());
		this->renderer.push_back(animatedImage);
	}
}

void GameObject::ChangeSourcePosSize(Vector2 pos, Vector2 size)
{
	renderer[0]->SetSourcePos(pos);
	renderer[0]->SetSourceSize(size);
	renderer[0]->UpdateTargetRect();
}

void GameObject::SetPosition(int x, int y)
{
	transform.position.x = x;
	transform.position.y = y;
	renderer[0]->SetPosition( x, y );	
}

void GameObject::Update(float dt)
{
}

void GameObject::Render()
{
	
}

Renderer* GameObject::GetRenderer()
{
	return nullptr;
}

//Renderer* GameObject::GetRenderer()
//{
//	return renderer;
//}
