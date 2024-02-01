#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
	background = Tile(false);

	isAudioOn = true;

	// ------ BACKGROUND LOAD TEXTURE
	background.LoadTexture(RM->GetRenderer(), "resources/mainMenu.jpg", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 0.8, 0.74 }, 0, 0, false, 0);
}

void MainMenuScene::Update(float dt)
{
	// ------ BUTTON PLAY
	//Check if the mouse is inside the render rect
	int widthPlay = 28 * playText.text.length();
	int heightPlay = 40;

	int XPlay = playText.position[0] - (widthPlay / 2);
	int YPlay = playText.position[1] - heightPlay / 2;
	//sampleText.position --> x, y


	int mouseXPlay = IM->GetMouseX();
	int mouseYPlay = IM->GetMouseY();

	bool isInsideAABBXPlay = mouseXPlay > XPlay && mouseXPlay < playText.position[0] + widthPlay;
	bool isInsideAABBYPlay = mouseYPlay > YPlay && mouseYPlay < playText.position[1] + heightPlay;

	if (isInsideAABBXPlay && isInsideAABBYPlay) {
		buttonAnglePlay += 0.05;
		if (SDL_GetMouseState(&mouseXPlay, &mouseYPlay) & SDL_BUTTON(SDL_BUTTON_LEFT))
			SM->SetScene("Gameplay Scene");
	}
	else
		buttonAnglePlay = 0;

	// ------ BUTTON RANKING
	//Check if the mouse is inside the render rect
	int widthRanking = 28 * rankingText.text.length();
	int heightRanking = 40;

	int XRanking = rankingText.position[0] - (widthRanking / 2);
	int YRanking = rankingText.position[1] - heightRanking / 2;

	int mouseXRanking = IM->GetMouseX();
	int mouseYRanking = IM->GetMouseY();

	bool isInsideAABBXRanking = mouseXRanking > XRanking && mouseXRanking < rankingText.position[0] + widthRanking;
	bool isInsideAABBYRanking = mouseYRanking > YRanking && mouseYRanking < rankingText.position[1] + heightRanking;

	if (isInsideAABBXRanking && isInsideAABBYRanking) {
		buttonAngleRanking += 0.05;
		if (SDL_GetMouseState(&mouseXRanking, &mouseYRanking) & SDL_BUTTON(SDL_BUTTON_LEFT))
			SM->SetScene("Ranking");
	}
	else
		buttonAngleRanking = 0;

	// ------ BUTTON AUDIO
	//Check if the mouse is inside the render rect
	int widthAudio = 28 * audioText.text.length();
	int heightAudio = 40;

	int XAudio = audioText.position[0] - (widthAudio / 2);
	int YAudio = audioText.position[1] - heightAudio / 2;

	int mouseXAudio = IM->GetMouseX();
	int mouseYAudio = IM->GetMouseY();

	bool isInsideAABBXAudio = mouseXAudio > XAudio && mouseXAudio < audioText.position[0] + widthAudio;
	bool isInsideAABBYAudio = mouseYAudio > YAudio && mouseYAudio < audioText.position[1] + heightAudio;

	if (isInsideAABBXAudio && isInsideAABBYAudio) {
		buttonAngleAudio += 0.05;
		if (SDL_GetMouseState(&mouseXAudio, &mouseYAudio) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			isAudioOn = !isAudioOn;
			if (isAudioOn)
			{
				audioText.text = "Audio On";
				AM->ToggleAudio();
				AM->PlayClip("musicaMenu", 2);
			}
			else
			{
				audioText.text = "Audio Off";
				AM->ToggleAudio();
			}
		}
	}
	else
		buttonAngleAudio = 0;

	// ------ BUTTON EXIT
	//Check if the mouse is inside the render rect
	int widthExit = 28 * exitText.text.length();
	int heightExit = 40;

	int XExit = exitText.position[0] - (widthExit / 2);
	int YExit = exitText.position[1] - heightExit / 2;

	int mouseXExit = IM->GetMouseX();
	int mouseYExit = IM->GetMouseY();

	bool isInsideAABBXExit = mouseXExit > XExit && mouseXExit < exitText.position[0] + widthExit;
	bool isInsideAABBYExit = mouseYExit > YExit && mouseYExit < exitText.position[1] + heightExit;

	if (isInsideAABBXExit && isInsideAABBYExit) {
		buttonAngleExit += 0.05;
		if (SDL_GetMouseState(&mouseXExit, &mouseYExit) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			RM->Quit();
		}
	}
	else
		buttonAngleExit = 0;
}

void MainMenuScene::Render(SDL_Renderer* renderer)
{
	// ------ BACKGROUND
	background.Render();

	// ------ PLAY BUTTON
	//width
	int widthPlay = 28 * playText.text.length();
	//height
	int heightPlay = 50;
	//color
	SDL_Color colorPlay = {255, 255, 255};
	//surface
	surfacePlay = TTF_RenderText_Solid(font, playText.text.c_str(), colorPlay);

	assert(surfacePlay != nullptr);

	//Textura
	texturePlay = SDL_CreateTextureFromSurface(renderer, surfacePlay);
	//assert(texturePlay != nullptr);

	SDL_SetTextureAlphaMod(texturePlay, 255); //Para que un text ose haga transparente -> 255 = max opacidad


	//Dibujar
	SDL_Rect renderRectPlay =
	{
		playText.position[0] - widthPlay / 2,
		playText.position[1] - heightPlay / 2,
		widthPlay,
		heightPlay
	};

	SDL_RenderCopyEx(
		renderer,		// Renderer
		texturePlay,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRectPlay,	// Where do we want to draw and size
		sin(buttonAnglePlay * (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surfacePlay);
	SDL_DestroyTexture(texturePlay);


	// ------ RANKING BUTTON
	//width
	int widthRanking = 28 * rankingText.text.length();
	//height
	int heightRanking = 50;
	//color
	SDL_Color colorRanking = { 255, 255, 255 };
	//surface
	surfaceRanking = TTF_RenderText_Solid(font, rankingText.text.c_str(), colorRanking);

	assert(surfaceRanking != nullptr);

	//Textura
	textureRanking = SDL_CreateTextureFromSurface(renderer, surfaceRanking);
	//assert(textureRanking != nullptr);

	SDL_SetTextureAlphaMod(textureRanking, 255); //Para que un text ose haga transparente -> 255 = max opacidad


	//Dibujar
	SDL_Rect renderRectRanking =
	{
		rankingText.position[0] - widthRanking / 2,
		rankingText.position[1] - heightRanking / 2,
		widthRanking,
		heightRanking
	};

	SDL_RenderCopyEx(
		renderer,		// Renderer
		textureRanking,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRectRanking,	// Where do we want to draw and size
		sin(buttonAngleRanking * (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surfaceRanking);
	SDL_DestroyTexture(textureRanking);


	// ------ AUDIO BUTTON
	///width
	int widthAudio = 28 * audioText.text.length();
	//height
	int heightAudio = 50;
	//color
	SDL_Color colorAudio = { 255, 255, 255 };
	//surface
	surfaceAudio = TTF_RenderText_Solid(font, audioText.text.c_str(), colorAudio);

	assert(surfaceAudio != nullptr);

	//Textura
	textureAudio = SDL_CreateTextureFromSurface(renderer, surfaceAudio);
	//assert(textureAudio != nullptr);

	SDL_SetTextureAlphaMod(textureAudio, 255); //Para que un text ose haga transparente -> 255 = max opacidad


	//Dibujar
	SDL_Rect renderRectAudio =
	{
		audioText.position[0] - widthAudio / 2,
		audioText.position[1] - heightAudio / 2,
		widthAudio,
		heightAudio
	};


	SDL_RenderCopyEx(
		renderer,		// Renderer
		textureAudio,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRectAudio,	// Where do we want to draw and size
		sin(buttonAngleAudio * (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surfaceAudio);
	SDL_DestroyTexture(textureAudio);


	// ------ EXIT BUTTON
	//width
	int widthExit = 28 * exitText.text.length();
	//height
	int heightExit = 50;
	//color
	SDL_Color colorExit = { 255, 255, 255 };
	//surface
	surfaceExit = TTF_RenderText_Solid(font, exitText.text.c_str(), colorExit);

	assert(surfaceExit != nullptr);

	//Textura
	textureExit = SDL_CreateTextureFromSurface(renderer, surfaceExit);
	//assert(textureExit != nullptr);

	SDL_SetTextureAlphaMod(textureExit, 255); //Para que un text ose haga transparente -> 255 = max opacidad


	//Dibujar
	SDL_Rect renderRectExit =
	{
		exitText.position[0] - widthExit / 2,
		exitText.position[1] - heightExit / 2,
		widthExit,
		heightExit
	};

	SDL_RenderCopyEx(
		renderer,		// Renderer
		textureExit,		// Target texture
		NULL,			// Texture part we want to draw
		&renderRectExit,	// Where do we want to draw and size
		sin(buttonAngleExit 
			* (3.14f * 2.0f) / 180.0f) * 10,	// Angle
		NULL,			// Center of the sprite
		SDL_FLIP_NONE	// Flip the sprite
	);

	SDL_FreeSurface(surfaceExit);
	SDL_DestroyTexture(textureExit);
}

void MainMenuScene::OnEnter(){
	
	std::cout << "ENTRO MAIN MENU" << std::endl;

	//INIT TTF
	assert(TTF_Init() != -1);

	font = TTF_OpenFont("resources/fonts/theRealFont.ttf", 28);
	assert(font != nullptr);

	playText.text = "Play";
	playText.position[0] = 260;
	playText.position[1] = 130;
	buttonAnglePlay = 0;
	
	rankingText.text = "Ranking";
	rankingText.position[0] = 260;
	rankingText.position[1] = 190;
	buttonAngleRanking = 0;

	audioText.text = "Audio On";
	audioText.position[0] = 260;
	audioText.position[1] = 250;
	buttonAngleAudio = 0;

	exitText.text = "Exit";
	exitText.position[0] = 260;
	exitText.position[1] = 310;
	buttonAngleExit = 0;

	AM->PlayClip("musicaMenu", 2);
}

void MainMenuScene::OnExit(){
	std::cout << "SALGO MAIN MENU" << std::endl;

	AM->MuteAudio();
}

void MainMenuScene::DestroySurfaceAndTexture()
{
	SDL_FreeSurface(surfacePlay);
	SDL_DestroyTexture(texturePlay);
	SDL_FreeSurface(surfaceRanking);
	SDL_DestroyTexture(textureRanking);
	SDL_FreeSurface(surfaceAudio);
	SDL_DestroyTexture(textureAudio);
	SDL_FreeSurface(surfaceExit);
	SDL_DestroyTexture(textureExit);
}
