#pragma once
#include "../dep/inc/xml/rapidxml.hpp"
#include "../dep/inc/xml/rapidxml_iterators.hpp"
#include "../dep/inc/xml/rapidxml_print.hpp"
#include "../dep/inc/xml/rapidxml_utils.hpp"
#include "Wave.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>


class LevelLoader
{
private:
	float totalTime;
public:
	LevelLoader();

	std::vector<Wave*> LoadWaves(std::string path, float levelTime);

	float GetTotalTime();
};

