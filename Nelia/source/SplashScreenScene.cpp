#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene()
{
	time = 0;

	SplashScreenRender();
}

void SplashScreenScene::SplashScreenRender()
{
	splashScene = Tile(false);

	splashScene.LoadTexture(RM->GetRenderer(), "resources/splashScreen.jpg", false, { 0,0, 512, 512 }, { 0,0, 512, 512 }, { 0.8, 0.74 }, 0, 0, false, 0);

}

void SplashScreenScene::Update(float dt){
	time += dt;

	if (time >= 3.0f) {
		SM->SetScene("Main Menu");
	}
}

void SplashScreenScene::Render(SDL_Renderer*){
	splashScene.Render();
}

void SplashScreenScene::OnEnter(){
	std::cout << "Entering Splash Screen" << std::endl;
}

void SplashScreenScene::OnExit(){
	std::cout << "Exiting Splash Screen" << std::endl;
}
