#include "HUD.h"

HUD::HUD()
{
	assert(TTF_Init() != -1);

	font = TTF_OpenFont("resources/fonts/theRealFont.ttf", 28);
	assert(font != nullptr);

	scoreText.text = "SCORE ";

	scoreText.position[0] = RM->windowWidth/6;
	scoreText.position[1] = RM->windowHeight - 450;

	score = 0;
	std::string textInt = std::to_string(score);
	scoreNum.text = textInt;
	scoreNum.position[0] = scoreText.position[0] + scoreText.text.length() + 60;
	scoreNum.position[1] = RM->windowHeight - 450;

}

void HUD::Render()
{
	//Text data
	//width
	int width = 15 * scoreText.text.length();
	//height
	int height = 15;
	//color
	SDL_Color color = { 255, 255, 255 };
	//surface
	SDL_Surface* surface = TTF_RenderText_Solid(font,scoreText.text.c_str(), color);

	assert(surface != nullptr);

	//Textura
	SDL_Texture* texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(texture != nullptr);

	SDL_SetTextureAlphaMod(texture, 255); //Para que un text ose haga transparente -> 255 = max opacidad

	//Dibujar
	SDL_Rect renderRect =
	{
		scoreText.position[0] - width / 2,
		scoreText.position[1] - height / 2,
		width,
		height
	};

	SDL_RenderCopyEx(
		RM->GetRenderer(),		// Renderer
		texture,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRect,	// Where do we want to draw and size
		sin(0 * (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

	//Text data
	//width
	int numWidth = 15 * scoreNum.text.length();
	//height
	int numHeight = 5;
	//surface
	SDL_Surface* numSurface = TTF_RenderText_Solid(font, scoreNum.text.c_str(), color);

	assert(numSurface != nullptr);

	//Textura
	SDL_Texture* numTexture = SDL_CreateTextureFromSurface(RM->GetRenderer(), numSurface);
	assert(numTexture != nullptr);

	SDL_SetTextureAlphaMod(numTexture, 255); //Para que un text ose haga transparente -> 255 = max opacidad

	//Dibujar
	SDL_Rect numRenderRect =
	{
		scoreNum.position[0] - numWidth / 2,
		scoreNum.position[1] - height / 2,
		numWidth,
		height
	};

	SDL_RenderCopyEx(
		RM->GetRenderer(),		// Renderer
		numTexture,		// Target texture
		NULL,			// Texture part we want to draw
		&numRenderRect,	// Where do we want to draw and size
		sin(0 * (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(numSurface);
	SDL_DestroyTexture(numTexture);
}

void HUD::UpdateScore(int score)
{
	this->score = score;
	std::string textInt = std::to_string(score);
	scoreNum.text = textInt;
	scoreNum.position[0] = scoreText.position[0] + scoreText.text.length() + 60;
	scoreNum.position[1] = RM->windowHeight - 450;
}


