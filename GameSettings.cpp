#include "GameSettings.h"

GameSettings::GameSettings() {
    autoMode = false;
    pictureResolution = 80;
    algorithm = 1;
    GameMap = Map(2);
}

GameSettings& GameSettings::getInstance() {
    static GameSettings instance;
    return instance;
}

void GameSettings::setMode(bool setMode) {
    autoMode = setMode;
}

bool GameSettings::getMode() const {
    return autoMode;
}

void GameSettings::setAlgorithm(int algoNum) {
    algorithm = algoNum;
}

int GameSettings::getAlgorithm() const {
    return algorithm;
}

void GameSettings::setSizeMap(int mapNum) {
    GameMap = Map(mapNum);
}

int GameSettings::getSizeMap() const {
    return GameMap.level;
}

Map GameSettings::getGameMap() {
    return GameMap;
}
