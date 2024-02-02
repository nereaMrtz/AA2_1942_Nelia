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
	const std::string RANKING_DATA_PATH= "resources/ranking.dat";

	static HighscoreManager* instance;
	HighscoreManager();

	std::map<int, std::string> scores;
	std::map<int, std::string> loadScore;

public:
	static HighscoreManager* GetInstance();
	//void LoadScores();
	void SaveScores();
	void AddScore(int value, std::string name);
	void ReadScores();
};

