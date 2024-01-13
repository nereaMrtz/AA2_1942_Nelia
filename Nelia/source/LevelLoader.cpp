#include "LevelLoader.h"

std::vector<Wave*> LevelLoader::LoadWaves(std::string path, float levelTime )
{
		std::vector<Wave*> waves;

	rapidxml::xml_document<> doc;
	std::ifstream file(path);
	if (file.is_open()) {
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());
		doc.parse<0>(&content[0]);


		rapidxml::xml_node<>* pRoot = doc.first_node();

		levelTime = (stof((std::string)pRoot->first_node()->value()));
		std::cout << levelTime << std::endl;

		/*for (rapidxml::xml_node<>* pNode = pRoot->first_node()->first_node(); pNode; pNode = pNode->next_sibling()) {

			float startTime = stof((std::string)pRoot->value());
			pRoot = pRoot->next_sibling();
			std::string pattern = (std::string)pRoot->first_attribute()->value();
			std::string type = (std::string)pRoot->value();
			pRoot = pRoot->next_sibling();
			int amount = stoi((std::string)pRoot->value());

			std::cout << startTime << std::endl;
			std::cout << pattern << std::endl;
			std::cout << type << std::endl;
			std::cout << type << std::endl;
		}*/


	}

	return waves;
}
