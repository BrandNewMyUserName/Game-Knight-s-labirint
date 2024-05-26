#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>


using namespace std;
using namespace sf;

//class Map {
//public:
//    vector<vector<int>> Grid;
//	int level;
//    int HEIGHT_MAP;
//    int WIDTH_MAP;
//
//	Map() {
//		level = 2;
//		loadMap(level);
//	}
//
//	Map(int level) {
//		this->level = level;
//		loadMap(this->level);
//	}
//
//	void loadMap(int number) {
//		level = number;
//		switch (level) {
//		case 1:
//			loadMap1();
//			break;
//		case 2:
//			loadMap2();
//			break;
//		case 3:
//			//loadMap2();
//			break;
//		default:
//			loadMap2();
//			break;
//		}
//	}
//
//	void loadMap1() {
//		HEIGHT_MAP = 10;
//		WIDTH_MAP = 10;
//		vector<string> Grid = {
//		"0000000000",
//		"0        0",
//		"0c0000 0 0",
//		"0 0    0 0",
//		"0 0    0k0",
//		"0 0 0  000",
//		"0   00   0",
//		"0 0d0 0000",
//		"0 0     t0",
//		"0000000000"
//		};
//	}
//
//	void loadMap2() {
//		HEIGHT_MAP = 20;
//		WIDTH_MAP = 20;
//		vector<string> Grid = {
//		"00000000000000000000",
//		"0     0      0000  0",
//		"0 0000  000    00  0",
//		"0 0       0    00  0",
//		"0 0  00   000      0",
//		"0    00 000  0     0",
//		"0 00 00    0 0 0   0",
//		"0 00  0    0 0 0   0",
//		"0 0    t  00 0 0   0",
//		"0 0 0000 000 0 0   0",
//		"0 0 0      0 0 0   0",
//		"0 0 0 0000 0 0 0   0",
//		"0 0 0    0 0 0 0   0",
//		"0 0 0    0 0   0   0",
//		"0 0 0 0000 0   0   0",
//		"0 0 0 0    0   0   0",
//		"0 0 0 0    00000   0",
//		"0 0 0 0      00    0",
//		"0 0 0 0      00    0",
//		"00000000000000000000"
//		};
//	}
//
//	friend class GameSettings;
//};

const int PICTURE_RESOLUTION = 80;
//const int WIDTH_MAP = 20;
//const int HEIGHT_MAP = 12;


const int HEIGHT_MAP = 25;//размер карты высота
const int WIDTH_MAP = 40;//размер карты ширина 

using namespace std;
using namespace sf;


class Map {
public:
	int level;
	vector<string> Grid;

	Map(int i) {
		level = i;
		Grid = {
"0000000000000000000000000000000000000000",
"0              t                       0",
"0 000  c                     0         0",
"0 000  c             k       0 0       0",
"0 000  c   0   00                      0",
"0 000          0                       0",
"0 000          0                       0",
"0 00          0                        0",
"0                                      0",
"0        0                             0",
"0                     0                0",
"0                                      0",
"0         000                          0",
"0                                      0",
"0                                      0",
"0               0                      0",
"0                                      0",
"0         0    00                      0",
"0                 0                    0",
"0           0000000                    0",
"0           0                          0",
"0           0                          0",
"0           0                          0",
"0                                      0",
"0000000000000000000000000000000000000000",
		};
	}

	Map() {
		level = 2;
		Grid = {
"0000000000000000000000000000000000000000",
"0              t                       0",
"0 000  c                     0         0",
"0 000  c             k       0 0       0",
"0 000  c   0   00                      0",
"0 000          0                       0",
"0 000          0                       0",
"0 00          0                        0",
"0                                      0",
"0        0                             0",
"0                     0                0",
"0                                      0",
"0         000                          0",
"0                                      0",
"0                                      0",
"0               0                      0",
"0                                      0",
"0         0    00                      0",
"0                 0                    0",
"0           0000000                    0",
"0           0                          0",
"0           0                          0",
"0           0                          0",
"0                                      0",
"0000000000000000000000000000000000000000",
		};
	}
	
};



