#pragma once
#include "Map.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;



typedef pair<int, int> Pair;

typedef pair<double, pair<int, int>> pPair;

class AStarSearch {
public:
    int grid[HEIGHT_MAP][WIDTH_MAP];
    Pair src;
    Pair dest;
    vector<Pair> path;
    bool foundDest;

    struct cell {
        int parent_i, parent_j;
        double f, g, h;
    };

    vector<vector<bool>> closedList;
    cell cellDetails[HEIGHT_MAP][WIDTH_MAP];

    bool isValid(int row, int col) {
        return (row >= 0) && (row < HEIGHT_MAP) && (col >= 0) && (col < WIDTH_MAP);
    }

    bool isUnBlocked(int row, int col) {
        return (grid[row][col] == 0);
    }

    bool isDestination(int row, int col, Pair dest) {
        return (row == dest.first && col == dest.second);
    }

    double calculateManhattanDistance(int row1, int col1, int row2, int col2) {
        return abs(row1 - row2) + abs(col1 - col2);
    }

    void tracePath(Pair dest, vector<Pair>& path) {
        int row = dest.first;
        int col = dest.second;

        while (!(cellDetails[row][col].parent_i == row &&
            cellDetails[row][col].parent_j == col)) {
            path.push_back(make_pair(row, col));
            int temp_row = cellDetails[row][col].parent_i;
            int temp_col = cellDetails[row][col].parent_j;
            row = temp_row;
            col = temp_col;
        }


        //ћожна зм≥нити координати м≥сц€ми
        path.push_back(make_pair(row, col));
        reverse(path.begin(), path.end());
        path.erase(path.begin());
    }

public:
    AStarSearch() {}



    AStarSearch(vector<string> inputGrid) {
        foundDest = false;
        closedList.resize(HEIGHT_MAP, vector<bool>(WIDTH_MAP, false));
        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++) {
                if (inputGrid[i][j] == '0' || inputGrid[i][j] == 'd')
                    grid[i][j] = 1;
                else
                    grid[i][j] = 0;
                if (inputGrid[i][j] == 'k' || inputGrid[i][j] == 'k')
                    dest = make_pair(i, j);
                cellDetails[i][j].f = numeric_limits<double>::max();
                cellDetails[i][j].g = numeric_limits<double>::max();
                cellDetails[i][j].h = numeric_limits<double>::max();
                cellDetails[i][j].parent_i = -1;
                cellDetails[i][j].parent_j = -1;
            }
        }
    }

    bool search(int x_pos, int y_pos) {
        src = make_pair(y_pos, x_pos);

        if (!isValid(src.first, src.second) || !isValid(dest.first, dest.second) ||
            !isUnBlocked(src.first, src.second) || !isUnBlocked(dest.first, dest.second)) {
            return false;
        }

        if (isDestination(src.first, src.second, dest)) {
            foundDest = true;
            return true;
        }

        cellDetails[src.first][src.second].f = 0.0;
        cellDetails[src.first][src.second].g = 0.0;
        cellDetails[src.first][src.second].h = 0.0;
        cellDetails[src.first][src.second].parent_i = src.first;
        cellDetails[src.first][src.second].parent_j = src.second;

        priority_queue<pPair, vector<pPair>, greater<pPair>> openList;
        openList.push(make_pair(0.0, make_pair(src.first, src.second)));

        while (!openList.empty()) {
            pPair p = openList.top();
            openList.pop();

            int i = p.second.first;
            int j = p.second.second;
            closedList[i][j] = true;

            int x_val[] = { 0, 0, 1, -1 };
            int y_val[] = { 1, -1, 0, 0 };

            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + y_val[dir];
                int nj = j + x_val[dir];

                if (!isValid(ni, nj) || closedList[ni][nj] || !isUnBlocked(ni, nj))
                    continue;

                if (isDestination(ni, nj, dest)) {
                    cellDetails[ni][nj].parent_i = i;
                    cellDetails[ni][nj].parent_j = j;
                    tracePath(dest, path);
                    foundDest = true;
                    return true;
                }

                double gNew = cellDetails[i][j].g + 1.0;
                double hNew = calculateManhattanDistance(ni, nj, dest.first, dest.second);
                double fNew = gNew + hNew;

                if (fNew < cellDetails[ni][nj].f) {
                    openList.push(make_pair(fNew, make_pair(ni, nj)));
                    cellDetails[ni][nj].f = fNew;
                    cellDetails[ni][nj].g = gNew;
                    cellDetails[ni][nj].h = hNew;
                    cellDetails[ni][nj].parent_i = i;
                    cellDetails[ni][nj].parent_j = j;
                }
            }
        }

        return false;
    }

    vector<Pair> backPath() {
        return path;
    }

    bool isDestinationFound() {
        return foundDest;
    }
};