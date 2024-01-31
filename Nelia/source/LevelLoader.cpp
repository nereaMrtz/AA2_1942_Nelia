#include "LevelLoader.h"

LevelLoader::LevelLoader()
{
}

std::vector<Wave*> LevelLoader::LoadWaves(std::string path, float levelTime)
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


		rapidxml::xml_node<>* pRoot = doc.first_node(); //stage

		levelTime = (stof((std::string)pRoot->first_node()->value())); // totaltime 50
		std::cout << levelTime << std::endl;

		for (rapidxml::xml_node<>* pNode = pRoot->first_node()->next_sibling(); pNode; pNode = pNode->next_sibling()) { //wave

			float startTime = stof((std::string)pNode->first_node()->value());
			//pRoot = pRoot->next_sibling();
			std::string pattern;
			if (pNode->first_node()->next_sibling()->first_attribute())
				pattern = pNode->first_node()->next_sibling()->first_attribute()->value();
			std::string type = pNode->first_node()->next_sibling()->value();
			//pRoot = pRoot->next_sibling();
			int amount = std::stoi(pNode->first_node()->next_sibling()->next_sibling()->value());

		//	std::cout << startTime << std::endl;
		//	std::cout << pattern << std::endl;
		//	std::cout << type << std::endl;
		//	std::cout << amount << std::endl;

			MovementPattern pat;
			WaveType ty;

			if (pattern == "V"){
				pat = MovementPattern::V;
			}
			else if (pattern == "O") {
				pat = MovementPattern::O;
			}
			else if (pattern == "I") {
				pat = MovementPattern::I;
			}
			else {
				pat = MovementPattern::V;
			}

			if (type == "normal") {
				ty = WaveType::normal;
			}			
			else if (type == "medium_yellow") {
				ty = WaveType::medium_yellow;
			}
			else if (type == "big_green") {
				ty = WaveType::big_green;
			}
			else if (type == "small_red") {
				ty = WaveType::small_red;
			}


			waves.push_back(new Wave(startTime, ty, pat, amount));
		}


	}
	else {
		//std::cout << path << std::endl;
	}

	return waves;
}
