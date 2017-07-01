#include "GameManager.h"

// Singleton variable that is passed to all classes that ask for an instance of it.
static GameManager* manager;

GameManager* GameManager::getInstance()
{
	if (!manager)
	{
		manager = new GameManager();
	}
	return manager;
}

void GameManager::setChoice(bool choice)
{
	gameChoice = choice;
}

bool GameManager::getChoice()
{
	return gameChoice;
}