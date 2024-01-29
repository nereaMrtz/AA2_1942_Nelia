#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager(){

}

//Adds a scene to the scene map
void SceneManager::AddScene(std::string name, Scene* s)
{
	scenes.emplace(name, s); // Agregacion
}


SceneManager* SceneManager::GetInstance() {
	if (instance == nullptr)
		instance = new SceneManager();
	
	return instance;
}

//template <class S> S* SceneManager::GetScene() {
//	std::map<std::string, Scene*>::iterator scene = scenes.find(typeid(S)); //Scene esta apuntando a la pos del map. Si no lo encuentra, scene apuntara al final
//	
//	bool sceneFound = scene != scenes.end();
//
//	return sceneFound ? dynamic_cast<S*>(scene->second) : nullptr; //Si encuentras la escena del tipo S (el que le pases) devuelvela, sino nullptr
//
//}

//Looks into the scene map for a scene with a name and returns nullptr if not found
Scene* SceneManager::GetScene(std::string name) {
	auto scene = scenes.find(name);

	bool sceneFound = scene != scenes.end();
	return sceneFound ? scenes[name] : nullptr;
}

//Returns a pointer to the current active scene
Scene* SceneManager::GetCurrentScene(){
	return currentScene;
}

void SceneManager::SetScene(std::string name){
	auto scene = scenes.find(name);
	
	bool sceneFound = scene != scenes.end();

	//Stop the code to warn the developer
	assert(sceneFound);
	if (sceneFound)	{
		if (currentScene != nullptr)
			currentScene->OnExit();
		currentScene = scene->second;
		currentScene->OnEnter();
	}
}

void SceneManager::ClearScene()
{
	scenes.clear();
}