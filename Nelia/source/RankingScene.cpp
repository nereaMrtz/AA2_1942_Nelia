#include "RankingScene.h"

RankingScene::RankingScene()
{
	background = Tile(false);

	// ------ BACKGROUND LOAD TEXTURE
	background.LoadTexture(RM->GetRenderer(), "resources/mainMenu.jpg", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 0.8, 0.74 }, 0, 0, false, 0);
}

void RankingScene::Update(float dt)
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

void RankingScene::Render(SDL_Renderer*)
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


	//////////////////   PLAYERS


	//Text data
	//width
	int widthS = 15 * scoresText.text.length();
	//height
	int heightS = 15;
	//color
	SDL_Color colorS = { 255, 255, 255 };
	//surface
	SDL_Surface* surfaceS = TTF_RenderText_Solid(font, scoresText.text.c_str(), colorS);

	assert(surfaceS != nullptr);

	//Textura
	SDL_Texture* textureS = SDL_CreateTextureFromSurface(RM->GetRenderer(), surfaceS);
	assert(textureS != nullptr);

	SDL_SetTextureAlphaMod(textureS, 255); //Para que un text ose haga transparente -> 255 = max opacidad

	//Dibujar
	SDL_Rect renderRectS =
	{
		scoresText.position[0] - widthS / 2,
		scoresText.position[1] - heightS / 2,
		widthS,
		heightS
	};

	SDL_RenderCopyEx(
		RM->GetRenderer(),		// Renderer
		textureS,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRectS,	// Where do we want to draw and size
		0,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surfaceS);
	SDL_DestroyTexture(textureS);

}

void RankingScene::OnEnter()
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

	HM->ReadScores();

	std::map<int, std::string> rankingScores = HM->GetScores();
	std::map<int, std::string> orderedScores;
	

	std::map<int, std::string>::reverse_iterator it;
	for (it = rankingScores.rbegin(); it != rankingScores.rend(); it++) {

		int i = 0;

		std::cout << "(" << (*it).first << ", " << (*it).second
			<< ")" << std::endl;
		
		
		assert(TTF_Init() != -1);

		font = TTF_OpenFont("resources/fonts/theRealFont.ttf", 28);
		assert(font != nullptr);

		std::string textInt = std::to_string((*it).first) + "    " + (*it).second;

		scoresText.text = textInt;
		scoresText.position[0] = 250;
		scoresText.position[1] += 90;
		i++;
	}

}



void RankingScene::OnExit()
{
	AM->MuteAudio();
}