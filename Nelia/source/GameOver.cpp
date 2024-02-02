#include "GameOver.h"

GameOver::GameOver()
{
	background = Tile(false);

	// ------ BACKGROUND LOAD TEXTURE
	background.LoadTexture(RM->GetRenderer(), "resources/mainMenu.jpg", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 0.8, 0.74 }, 0, 0, false, 0);
}

void GameOver::Update(float dt)
{
	//Check if the mouse is inside the render rect
	int width = 18 * backToMenu.text.length();
	int height = 40;

	int X = backToMenu.position[0] - (width / 2);
	int Y = backToMenu.position[1] - height / 2;

	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMouseY();

	bool isInsideAABBX = mouseX > X && mouseX < backToMenu.position[0] + width;
	bool isInsideAABBY = mouseY > Y && mouseY < backToMenu.position[1] + height;

	if (isInsideAABBX && isInsideAABBY) {
		buttonAngle += 0.05;
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			SM->SetScene("Main Menu");
		}
	}
	else
		buttonAngle = 0;
}

void GameOver::Render(SDL_Renderer*)
{
	// ------ BACKGROUND
	background.Render();

	// ------ BUTTON
	//width
	int width = 28 * backToMenu.text.length();
	//height
	int height = 50;
	//color
	SDL_Color color = { 255, 255, 255 };
	//surface
	SDL_Surface* surface = TTF_RenderText_Solid(font, backToMenu.text.c_str(), color);

	assert(surface != nullptr);

	//Textura
	SDL_Texture* texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	//assert(texturePlay != nullptr);

	SDL_SetTextureAlphaMod(texture, 255); //Para que un text ose haga transparente -> 255 = max opacidad

	//Dibujar
	SDL_Rect renderRect =
	{
		backToMenu.position[0] - width / 2,
		backToMenu.position[1] - height / 2,
		width,
		height
	};

	SDL_RenderCopyEx(
		RM->GetRenderer(),		// Renderer
		texture,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRect,	// Where do we want to draw and size
		sin(buttonAngle * (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void GameOver::OnEnter()
{
	//INIT TTF
	assert(TTF_Init() != -1);

	font = TTF_OpenFont("resources/fonts/theRealFont.ttf", 28);
	assert(font != nullptr);

	backToMenu.text = "Back to Menu";
	backToMenu.position[0] = 250;
	backToMenu.position[1] = 400;
	buttonAngle = 0;

	AM->PlayMusic("musicaMenu");
}

void GameOver::OnExit()
{
	AM->MuteAudio();
}
