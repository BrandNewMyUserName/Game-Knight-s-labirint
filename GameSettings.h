#pragma once
#include"Map.h"
class GameSettings
{
protected:
	static bool autoMode;
	static int sizeMap;
	static int algorithm;
	static Map GameMap;


	GameSettings() {
		setAutoMode(0);
		setAlgorithm(1);
		setSizeMap(2);
	}

	void setAutoMode(bool setMode);
	void setAlgorithm(int algoNum);
	void setSizeMap(int mapNum);
	bool IsAutoMode();

};

