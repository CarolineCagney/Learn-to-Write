#pragma once

class GameManager
{
private:

	// States whether game is chosen by player or a-z
	bool gameChoice;

	GameManager(){	}
public:
	static GameManager* getInstance();
	void setChoice(bool);
	bool getChoice();

};