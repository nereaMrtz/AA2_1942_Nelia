#include "HighscoreManager.h"

HighscoreManager* HighscoreManager::instance = nullptr;

HighscoreManager::HighscoreManager()
{
}

HighscoreManager* HighscoreManager::GetInstance()
{
	if (instance == nullptr)
		instance = new HighscoreManager();

	return instance;
}

void HighscoreManager::LoadScores(std::string path)
{
	rapidxml::xml_document<> doc;
	std::ifstream file(path);
	if (file.is_open()) {
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());
		doc.parse<0>(&content[0]);


		rapidxml::xml_node<>* pRoot = doc.first_node(); // players

		for (rapidxml::xml_node<>* pNode = pRoot->first_node(); pNode; pNode = pNode->next_sibling()) {

			std::string name = pNode->first_node()->value();

			int score = std::stoi(pNode->first_node()->next_sibling()->value());

			std::cout << name << std::endl;
			std::cout << score << std::endl;
		}
	}
}

void HighscoreManager::SaveScores(std::string path)
{
	std::ofstream myFile;

	myFile.open("resources/ranking.dat");
	std::cout << "entro" << std::endl;

	if (myFile.is_open()) {
		
		for (auto it = scores.begin(); it != scores.end(); it++) {

			size_t size = it->second.size();


			//myFile << it->first;
			//myFile << it->second;

			myFile.write(it->second.c_str(), size);
		}
	}
}

void HighscoreManager::AddScore(int value, std::string name)
{
	scores.insert(std::pair<int,std::string>(value, name));
}
