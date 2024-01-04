#pragma once
#include <map>
#include <string>
#include "Scene.h"
#include <assert.h>

#define SM SceneManager::GetInstance() // va a hacer que cada vez que escribamos SM es como escribir la funcion

class SceneManager {
public:
	//-----Agregation
	void AddScene(std::string name,Scene* s);
	
	//template <class S> S* GetScene(); // Me va a devolver un puntero a la clase que le diga
	
	//-----getters
	Scene* GetScene(std::string name);
	Scene* GetCurrentScene();

	//template <class S> S* SetScene(); 
	
	//-----setters
	void SetScene(std::string name);

	//-----singleton
	static SceneManager* GetInstance();


private:
	SceneManager(); //El constructor es privado porque no queremos que no lo gestione otra gente
	static SceneManager* instance; 
	std::map<std::string, Scene*> scenes;
	Scene* currentScene;
};