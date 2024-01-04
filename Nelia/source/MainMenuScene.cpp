#include "MainMenuScene.h"

void MainMenuScene::Update(float dt)
{
	//Check if the mouse is inside the render rect
	int width = 28 * sampleText.text.length();
	int height = 50;

	int X = sampleText.position[0] - width / 2;
	int Y = sampleText.position[1] - height / 2;
	//sampleText.position --> x, y


	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMouseY();

	bool isInsideAABBX = mouseX > X && mouseX < sampleText.position[0] + width;
	bool isInsideAABBY = mouseY > Y && mouseY < sampleText.position[1] + height;

	if (isInsideAABBX && isInsideAABBY) {
		buttonAngle += 0.05;
		if (IM->CheckKeyState(SDLK_j, PRESSED))
			SM->SetScene("Splash Screen");
	}
	else
		buttonAngle = 0;
}

void MainMenuScene::Render(SDL_Renderer* renderer)
{
	//Text data
	//width
	int width = 28 * sampleText.text.length();
	//height
	int height = 50;
	//color
	SDL_Color color = {0, 0, 0};
	//surface
	SDL_Surface* surface = TTF_RenderText_Solid(font, sampleText.text.c_str(), color);

	assert(surface != nullptr);

	//Textura
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	assert(texture != nullptr);

	SDL_SetTextureAlphaMod(texture, 255); //Para que un text ose haga transparente -> 255 = max opacidad


	//Dibujar
	SDL_Rect renderRect =
	{
		sampleText.position[0] - width / 2,
		sampleText.position[1] - height / 2,
		width,
		height
	};

	SDL_RenderCopyEx(
		renderer,		// Renderer
		texture,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRect,	// Where do we want to draw and size
		sin(buttonAngle* (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

}

void MainMenuScene::OnEnter(){
	//INIT TTF
	assert(TTF_Init() != -1);

	font = TTF_OpenFont("resources/fonts/hyperspace.ttf", 28);
	assert(font != nullptr);
	sampleText.text = "AAAAAAAAA";
	sampleText.position[0] = 250;
	sampleText.position[1] = 250;
	buttonAngle = 0;

}

void MainMenuScene::OnExit(){
	
}
