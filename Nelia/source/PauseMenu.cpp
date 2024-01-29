#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	background = Tile(false);


	// ------ BACKGROUND LOAD TEXTURE
	background.LoadTexture(RM->GetRenderer(), "resources/mainMenu.jpg", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 0.8, 0.74 }, 0, 0, false, 0);
}

void PauseMenu::Update(float dt)
{
	//Check if the mouse is inside the render rect
	int width = 28 * resume.text.length();
	int height = 50;

	int X = resume.position[0] - (width / 2);
	int Y = resume.position[1] - height / 2;

	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMouseY();

	bool isInsideAABBX = mouseX > X && mouseX < resume.position[0] + width;
	bool isInsideAABBY = mouseY > Y && mouseY < resume.position[1] + height;

	if (isInsideAABBX && isInsideAABBY) {
		buttonAngle += 0.05;
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			SM->SetScene("Gameplay Scene");
			OnExit();
		}
	}
	if (IM->CheckKeyState(SDLK_ESCAPE, PRESSED)) {
		SM->GetScene("Gameplay Scene");
		OnExit();
	}
	else
		buttonAngle = 0;
}

void PauseMenu::Render(SDL_Renderer* renderer)
{
	// ------ BACKGROUND
	background.Render();

	// ------ BUTTON
	//width
	int width = 28 * resume.text.length();
	//height
	int height = 50;
	//color
	SDL_Color color = { 255, 255, 255 };
	//surface
	surface = TTF_RenderText_Solid(font, resume.text.c_str(), color);

	assert(surface != nullptr);

	//Textura
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	//assert(texturePlay != nullptr);

	SDL_SetTextureAlphaMod(texture, 255); //Para que un text ose haga transparente -> 255 = max opacidad

	//Dibujar
	SDL_Rect renderRect =
	{
		resume.position[0] - width / 2,
		resume.position[1] - height / 2,
		width,
		height
	};

	SDL_RenderCopyEx(
		renderer,		// Renderer
		texture,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRect,	// Where do we want to draw and size
		sin(buttonAngle * (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	DestroySurfaceAndTexture();
}

void PauseMenu::OnEnter() {
	//INIT TTF
	assert(TTF_Init() != -1);

	font = TTF_OpenFont("resources/fonts/theRealFont.ttf", 28);
	assert(font != nullptr);

	resume.text = "Resume";
	resume.position[0] = 250;
	resume.position[1] = 250;
	buttonAngle = 0;
}

void PauseMenu::OnExit() {
	//SM->SetScene("Gameplay Scene");
}

void PauseMenu::DestroySurfaceAndTexture()
{

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
