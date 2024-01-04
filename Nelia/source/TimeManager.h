#pragma once
#include<SDL.h>

#define TM TimeManager::GetInstance()

class TimeManager
{
public:
    static TimeManager* GetInstance();

    void Update();

    //Current time
    float GetCtMillis();  
    float GetCtSec();

    //Delta time
    float GetDtMillis();  
    float GetDtSec();

    static const float FPS;
    static const float TICKS;

private:
    float dt;
    float time;

    static TimeManager* Instance;

    TimeManager();
};