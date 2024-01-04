#pragma once
#include <SDL.h>
#include "SceneManager.h"

#define RM RenderManager::GetInstance()

class RenderManager
{
private:
	static RenderManager* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;

	RenderManager(int widht, int height, int flags);

public:
	float windowWidth;
	float windowHeight;

	static RenderManager* GetInstance();
	SDL_Renderer* GetRenderer();

	void InitSDL();
	void InitWindowAndRenderer(int widht = 224, int height = 240, int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	void ClearScreen();
	void RenderScreen();

	void Quit();
};

