#pragma once
class ScoreManager
{
private:
	int score;

public:
	ScoreManager();
	void AddScore(int amount);

	int GetScore();
};

