#pragma once
#include "Map.h"

class GameSettings {
private:
    GameSettings();
    int pictureResolution = 80;
    bool autoMode;
    int algorithm;
    Map GameMap;


public:
    static GameSettings& getInstance();

    void setMode(bool setMode);
    bool getMode() const;

    void setAlgorithm(int algoNum);
    int getAlgorithm() const;

    void setSizeMap(int mapNum);
    int getSizeMap() const;

    Map getGameMap();

    GameSettings(const GameSettings&) = delete;
    GameSettings& operator=(const GameSettings&) = delete;
};
