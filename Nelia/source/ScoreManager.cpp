#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
	score = 0;
}

void ScoreManager::AddScore(int amount)
{
	score += amount;
}

int ScoreManager::GetScore()
{
	return score;
}
