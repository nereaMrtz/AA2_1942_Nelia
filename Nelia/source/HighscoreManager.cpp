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
			myFile.write(reinterpret_cast<char*>(&size), sizeof(size));

			myFile << it->first << ' ';
			myFile << it->second << '-' << '\0';

			//myFile.write(it->second.c_str(), size);
			//myFile << ' ';

			//std::cout << it->second.c_str() << std::endl;
		}
	}
	myFile.close();
}

void HighscoreManager::AddScore(int value, std::string name)
{
	scores.insert(std::pair<int,std::string>(value, name));
}

void HighscoreManager::ReadScores()
{
	std::string substr(size_t pos = 0, size_t len = std::string::npos);

	bool isNum = true;
	int size = 0;
	int lastSizeNum = 0;
	int lastSizeName = 0;
	int scoreValue = 0;

	std::ifstream myFile;
	myFile.open("resources/ranking.dat", std::ios::in | std::ios::binary);

	if (myFile.is_open()) {

		size_t totalSize = 0;
		myFile.read(reinterpret_cast<char*>(&totalSize), sizeof(totalSize));

		std::string buffer;
		std::string bufferAux;
		std::string otherString;

		buffer.resize(totalSize);
		myFile.read(&buffer[0], buffer.size());

		int* ptr = new int(0);

		bufferAux = buffer;
		for (auto i = 0; i != totalSize + 1; i++) {

			//ptr = &i;

			if (buffer[i] != '\0') {

				if (isNum) {
					if (buffer[i] == ' ') {
						ptr = &size;
						myFile.read(&bufferAux[*ptr], size);
						std::string newString = bufferAux.substr(lastSizeNum, size);
						bufferAux.resize(size + 1);
						
						std::cout << newString <<std::endl;

						bufferAux = buffer;
						bufferAux.resize(buffer.size() + 1);
						//otherString = bufferAux.substr(bufferAux[size], bufferAux.size());

						//std::cout << otherString << std::endl;

						size = 0;
						isNum = false;

						lastSizeName++;

					}
					else {
						size++;
						lastSizeName++;
					}
				}
				else {
					if (buffer[i] != '-') {
						size++;
						lastSizeNum++;
					}
					else{
						ptr = &size;
						myFile.read(&bufferAux[*ptr], size);
						std::string newString = bufferAux.substr(lastSizeName, size);
						bufferAux.resize(size + 1);


						std::cout << newString << std::endl;

						bufferAux = buffer;
						bufferAux.resize(buffer.size() + 1);

						
						size = 0;
						isNum = true;

						lastSizeNum++;

					}

				}
			}
			else if(buffer[i] == 1) {
				lastSizeNum++;
				lastSizeName++;
				std::cout << "SOH" << std::endl;
			}
			else {
				lastSizeNum++;
				lastSizeName++;
			}

		}

	}
	myFile.close();

}
