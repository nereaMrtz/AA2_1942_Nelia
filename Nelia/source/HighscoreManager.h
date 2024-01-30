#pragma once
#include "../dep/inc/xml/rapidxml.hpp"
#include "../dep/inc/xml/rapidxml_iterators.hpp"
#include "../dep/inc/xml/rapidxml_print.hpp"
#include "../dep/inc/xml/rapidxml_utils.hpp"

#include<map>
#include<iostream>
#include <sstream>


#define HM HighscoreManager::GetInstance()

class HighscoreManager
{
private:
	static HighscoreManager* instance;
	HighscoreManager();

	std::map<int, std::string> scores;

public:
	static HighscoreManager* GetInstance();
	void LoadScores(std::string path);
};

