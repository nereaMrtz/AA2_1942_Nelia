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
