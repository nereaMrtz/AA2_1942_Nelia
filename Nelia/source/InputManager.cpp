#include"InputManager.h"

InputManager* InputManager::instance = nullptr;


InputManager* InputManager::GetInstance()
{
	if (instance == nullptr)
		instance = new InputManager();

	return instance;
}

//Processes all the SDL input events ad updates the key map
void InputManager::Listen()
{
	//Update current events
	for (auto i = keys.begin(); i != keys.end(); i++)
	{
		if ((i->second & DOWN) > 0)
		{
			i->second = PRESSED;
		}
		else if ((i->second & UP) > 0)
		{
			i->second = RELEASED;
		}
	}

	//Mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	//Process SDL events
	SDL_Event evt;

	while (SDL_PollEvent(&evt))
	{
		if (evt.type == SDL_QUIT) {
			quitEvent = true;
		}
		else if (evt.type == SDL_KEYDOWN) {
			keys[evt.key.keysym.sym] = KeyState(DOWN | PRESSED);
		}
		else if (evt.type == SDL_KEYUP) {
			keys[evt.key.keysym.sym] = KeyState(UP | RELEASED);
		}
	}
}

//Returns true if the key is in the given state
bool InputManager::CheckKeyState(Sint32 key, KeyState state)
{
	if (keys.find(key) != keys.end())
	{
		//Key exists - check if state == value
		return ((int)keys[key] & (int)state) > 0;	//State != UNDEFINED
	}
	else
	{
		//Create key with undefined value
		keys.emplace(key, UNDEFINED);
		return (state & UNDEFINED) > 0;	//state contains undefined?
	}
}

int InputManager::GetMouseX()
{
	return mouseX;
}

int InputManager::GetMouseY()
{
	return mouseY;
}

bool InputManager::GetQuitEvent()
{
	return quitEvent;
}
