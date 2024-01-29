#include"GameEngine.h"

GameEngine::GameEngine(int x, int y) : isRunning(true)
{

}

#pragma region INITIALIZATION
void GameEngine::Init()
{
	//RM;
}
	

#pragma endregion

void GameEngine::Run(){
	SM->AddScene("Splash Screen", new SplashScreenScene());
	SM->SetScene("Splash Screen");
	SM->AddScene("Main Menu", new MainMenuScene());
	SM->AddScene("Gameplay Scene", new GameplayScene());

	while (isRunning)
	{
		TM->Update();
		IM->Listen();
		isRunning = !IM->GetQuitEvent();
		
		SM->GetCurrentScene()->Update(TM->GetDtSec());

		//RENDER
		RM->ClearScreen();
		SM->GetCurrentScene()->Render(RM->GetRenderer()); //Llama a la funcion render de la escena
		RM->RenderScreen();

	}
}


//Destroys all windows and renderers and quits SDL
void GameEngine::Quit()
{
	RM->Quit();
}
