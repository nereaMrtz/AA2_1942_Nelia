#pragma once
#include<unordered_map>
#include<SDL.h>

enum KeyState			//For BITMASK use		//	var >> x // dividir per 2 x vegades
{
	UNDEFINED = 1,		//Code tries to acces key but it hasn't been registered yet
	DOWN = 2,			//Frame when the key is pressed
	PRESSED = 4,		//The key is pressed
	UP = 8,				//Frame when the key is released
	RELEASED = 16		//Released
};

#define IM InputManager::GetInstance() //SIEMPRE SIN ;

class InputManager
{
private:
	std::unordered_map<Sint32, KeyState> keys;
	int mouseX;
	int	mouseY;
	bool quitEvent;
	InputManager() :quitEvent(false), mouseX(0), mouseY(0) {};
	static InputManager* instance;
public:
	static InputManager* GetInstance();
	void Listen();
	bool CheckKeyState(Sint32 key, KeyState state);
	int GetMouseX();
	int GetMouseY();
	bool GetQuitEvent();
};
