#include "TimeManager.h"
#include <iostream>

TimeManager* TimeManager::Instance = nullptr;

const float TimeManager::FPS = 60.f;
const float TimeManager::TICKS = 1.f / 60.f;


TimeManager* TimeManager::GetInstance()
{
    if (Instance == nullptr)
        Instance = new TimeManager();
  
    return Instance;
}

void TimeManager::Update()
{
    dt = SDL_GetTicks() - time;
    time = SDL_GetTicks();
    //std::cout << dt/1000.0f << std::endl;
}

float TimeManager::GetCtMillis()
{
    return time;
}

float TimeManager::GetCtSec()
{
    return time / 1000.0f;
}

float TimeManager::GetDtMillis()
{
    return dt;
}

float TimeManager::GetDtSec()
{
    return dt / 1000.0f;
}

TimeManager::TimeManager() : dt(0.f), time(0.f)
{
}