#include "GameObject.h"

void GameObject::LoadTexture(SDL_Renderer* renderer, std::string path, bool isAnimated, SDL_Rect targetRect, SDL_Rect sourceRect, Vector2 scale, int rows, int cols, bool looping, int offset)
{
	if (!isAnimated) {
		ImageRenderer* image = new ImageRenderer({ 255 }, 1, 0, targetRect, sourceRect, scale);
		image->Load(path.c_str());
		this->renderer.push_back(image);
	}
	else {
		AnimatedImageRenderer* animatedImage = new AnimatedImageRenderer(1, 0, targetRect, sourceRect, 3, looping,  scale, rows, cols, offset);
		animatedImage->Load(path.c_str());
		this->renderer.push_back(animatedImage);
	}
}

void GameObject::ChangeSourcePosSize(Vector2 pos, Vector2 size, int i)
{
	renderer[i]->SetSourcePos(pos);
	renderer[i]->SetSourceSize(size);
	renderer[i]->UpdateTargetRect();
}

void GameObject::SetPosition(int x, int y)
{
	transform.position.x = x;
	transform.position.y = y;
	renderer[0]->SetPosition( x, y );	
}

void GameObject::Update(float dt)
{
	physics.Update(dt);
	
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
