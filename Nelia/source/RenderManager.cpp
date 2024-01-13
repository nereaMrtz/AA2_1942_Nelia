#include "RenderManager.h"

RenderManager* RenderManager::instance = nullptr;

RenderManager::RenderManager(int widht = 512, int height = 512, int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE) //Cuando la ventana se cree que pueda cambiarse el tamaño
{
	this->windowWidth = widht;
	this->windowHeight = height;

	InitSDL();
	InitWindowAndRenderer(widht, height, flags);
}

RenderManager* RenderManager::GetInstance()
{
	if (instance == nullptr)
		instance = new RenderManager();
	return instance;
}

SDL_Renderer* RenderManager::GetRenderer()
{
	return renderer;
}

void RenderManager::InitSDL()
{
	//load SLD and check if it works
	int result = SDL_Init(SDL_INIT_VIDEO);

	bool succes = result >= 0;
	if (!succes)
	{
		throw SDL_GetError();
	}
}


void RenderManager::InitWindowAndRenderer(int widht, int height, int flags)
{
	int result = SDL_CreateWindowAndRenderer(widht, height, flags, &window, &renderer);

	bool succes = result >= 0;
	if (!succes)
	{
		throw SDL_GetError();
	}
}

void RenderManager::ClearScreen()
{
	SDL_SetRenderDrawColor(renderer, 255, 100, 255, 255);
	SDL_RenderClear(renderer);
}

void RenderManager::RenderScreen()
{
	SDL_RenderPresent(renderer);
}

void RenderManager::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


