#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

const int PICTURE_RESOLUTION = 32;
const int WIDTH_MAP = 20;
const int HEIGHT_MAP = 12;

using namespace std;
using namespace sf;


class Map {
public:
    
    vector<String> Grid = {
    "00000000000000000000",
    "01111111111111111110",
    "01000000000000000010",
    "01011111111111111101",
    "01010000000000000101",
    "01010111111111101010",
    "01010000000000101010",
    "01010111111111101010",
    "01000000000000000101",
    "01111111111111111110",
    "01000000000000000010",
    "01111111111111111110",
    "00000000000000000000"
        };

    Map() {

    }

};


//��������� �����
