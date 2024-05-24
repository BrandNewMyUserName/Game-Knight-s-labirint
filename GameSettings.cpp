#include "GameSettings.h"

void GameSettings::setAutoMode(bool mode)
{
	autoMode = mode;
}

bool GameSettings::IsAutoMode()
{
	return autoMode;
}

void GameSettings::setAlgorithm(int algoNum)
{
	if (IsAutoMode())
		algorithm = algoNum;
}

void GameSettings::setSizeMap(int mapNum) {
	GameMap = Map(mapNum);
}