#include "HighscoreManager.h"

HighscoreManager* HighscoreManager::instance = nullptr;

HighscoreManager::HighscoreManager()
{
	//scores.insert(std::pair<int, std::string>(0, " "));
}

HighscoreManager* HighscoreManager::GetInstance()
{
	if (instance == nullptr)
		instance = new HighscoreManager();

	return instance;
}

//void HighscoreManager::LoadScores()
//{
//	rapidxml::xml_document<> doc;
//	std::ifstream file("resources/ranking.dat");
//	if (file.is_open()) {
//		std::stringstream buffer;
//		buffer << file.rdbuf();
//		file.close();
//		std::string content(buffer.str());
//		doc.parse<0>(&content[0]);
//
//
//		rapidxml::xml_node<>* pRoot = doc.first_node(); // players
//
//		for (rapidxml::xml_node<>* pNode = pRoot->first_node(); pNode; pNode = pNode->next_sibling()) {
//
//			std::string name = pNode->first_node()->value();
//
//			int score = std::stoi(pNode->first_node()->next_sibling()->value());
//
//			std::cout << name << std::endl;
//			std::cout << score << std::endl;
//		}
//	}
//}

void HighscoreManager::SaveScores()
{
	std::ofstream myFile;

	myFile.open(RANKING_DATA_PATH, std::ios::binary | std::ios::trunc);


	if (myFile.is_open()) {
		std::cout << "entro" << std::endl;

		int scoresMapSize = scores.size();
		myFile.write(reinterpret_cast<char*>(&scoresMapSize), sizeof(int));
		
		for (auto it = scores.begin(); it != scores.end(); it++) {

			//saving score
			myFile.write(reinterpret_cast<char*>(const_cast<int*>(&it->first)), sizeof(int));
			
			//saving name
			size_t nameSize = it->second.size();
			myFile.write(reinterpret_cast<char*>(&nameSize), sizeof(size_t));
			std::string stringVal{ it->second };
			myFile.write(it->second.c_str(), nameSize);

			std::cout << "WRITTING: Score: " << it->first << "  " << stringVal << std::endl;

			//myFile << it->first << ' ';
			//myFile << it->second << '-' << '\0';


			//myFile << ' ';

			//std::cout << it->second.c_str() << std::endl;
		}
	}
	myFile.close();
}

void HighscoreManager::AddScore(int value, std::string name)
{
	scores.insert(std::pair<int,std::string>(value, name));
	//SaveScores();
}

void HighscoreManager::ReadScores()
{

	std::ifstream myFile;
	myFile.open(RANKING_DATA_PATH, std::ios::in | std::ios::binary);

	if (myFile.is_open()) {

		int totalSize = 0;
		myFile.read(reinterpret_cast<char*>(&totalSize), sizeof(int));

		if (totalSize <= 0)
		{
			//file is empty, no scores to display
			return;
		}

		scores.clear();

		//for each stored element...
		for ( ; totalSize > 0; totalSize--)
		{
			//score component
			int inScoreVal = -1;
			myFile.read(reinterpret_cast<char*>(&inScoreVal), sizeof(int));

			//name component
			size_t inNameSize = 0;
			myFile.read(reinterpret_cast<char*>(&inNameSize), sizeof(size_t));

			char* inNameBuffer = new char[inNameSize + 1];
			myFile.read(inNameBuffer, inNameSize);

			inNameBuffer[inNameSize] = '\0';
			std::string inName = inNameBuffer;
			delete[] inNameBuffer;

			scores.insert({ inScoreVal, inName });

			std::cout << "READING: Score: " << inScoreVal << "  " << inName << std::endl;
		}
	}
	myFile.close();
}

std::map<int, std::string> HighscoreManager::GetScores()
{
	return scores;
}
