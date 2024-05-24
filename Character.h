#pragma once
#include "A_star.h"
#include "Map.h"
#include "observed_area.h"
#include <cmath>
#include <algorithm>

class Character {
public:
    float x, y, speedMove, speedRun, h, w, dx, dy;
    int x_pos, y_pos, dir, playerScore;
    String Picture_name;
    Image characterImage;
    Texture characterTexture;
    Sprite characterSprite;
    Map MAP;
    AStarSearch navigation = AStarSearch(MAP.Grid);

    Character() : x_pos(1), y_pos(1), h(74), w(75), speedMove(0.05), speedRun(1 /*0.1*/), dir(0), dx(1), dy(0), Picture_name("images.png") {
        playerScore = 0;
        characterImage.loadFromFile("pictures/" + this->Picture_name);
        this->characterTexture.loadFromImage(this->characterImage);
        this->characterSprite.setTexture(this->characterTexture);
        this->characterSprite.setTextureRect(IntRect(8, 15, 180, 112));
        setMapPos();
        this->characterSprite.setPosition(x, y);
    }

    void autoove(float& CurrentFrame, float& time, bool& autoMode) {
        if (!navigation.path.empty()) {
            auto nextPos = navigation.path.front();

            if ((x - nextPos.second * PICTURE_RESOLUTION) == 0 && (y - nextPos.first * PICTURE_RESOLUTION) == 0) {
                navigation.path.erase(navigation.path.begin());
                nextPos = navigation.path.front();
            }
                


            //int dir_x = nextPos.second - x_pos;
            //int dir_y = nextPos.first - y_pos;

            int pix_dist_x = nextPos.second * PICTURE_RESOLUTION - x;
            int pix_dist_y = nextPos.first * PICTURE_RESOLUTION - y;

            setDir(pix_dist_x, pix_dist_y);

            autoChangeSpike(CurrentFrame, time);

            setDirection(time);
            update(time, autoMode);

        }
        else {
            autoMode = 0;
        }
    }

    void autoMove(float& CurrentFrame, float& time, bool& autoMode) {
            auto nextPos = navigation.path.front();

            if ((x - nextPos.second * PICTURE_RESOLUTION) == 0 && (y - nextPos.first * PICTURE_RESOLUTION) == 0) {
                navigation.path.erase(navigation.path.begin());
                if (!navigation.path.empty())
                    nextPos = navigation.path.front();
                else {
                    autoMode = 0;
                    return;
                }      
            }

            int pix_dist_x = nextPos.second * PICTURE_RESOLUTION - x;
            int pix_dist_y = nextPos.first * PICTURE_RESOLUTION - y;

            setDir(pix_dist_x, pix_dist_y);

            autoChangeSpike(CurrentFrame, time);

            setDirection(time);
            update(time, autoMode);

    }

    void autoChangeSpike(float& CurrentFrame, float& time) {
        int coordinates[3][3] = {
            {76, 250, 430},
            {25, 210, 400},
            {66, 250, 435}
        };

        switch (dir) {
        case 0:
            CurrentFrame += speedMove;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[0][static_cast<int>(CurrentFrame)], 25, 75, 74));
            break;
        case 1:
            CurrentFrame += speedMove;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(600, coordinates[1][static_cast<int>(CurrentFrame)], 75, 74));
            break;
        case 2:
            CurrentFrame += speedMove;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[0][static_cast<int>(CurrentFrame)], 400, 75, 74));
            break;
        case 3:
            CurrentFrame += speedMove;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[2][static_cast<int>(CurrentFrame)], 210, 75, 74));
            break;
        }
    }

    void placeInAngle() {
        characterSprite.setPosition(y_pos * PICTURE_RESOLUTION, x_pos * PICTURE_RESOLUTION);
        y = y_pos * PICTURE_RESOLUTION;
        x = x_pos * PICTURE_RESOLUTION;
    }

    void getGridPos() {
        x_pos = x / PICTURE_RESOLUTION;
        y_pos = y / PICTURE_RESOLUTION;
    }

    void setMapPos() {
        x = x_pos * PICTURE_RESOLUTION;
        y = y_pos * PICTURE_RESOLUTION;
    }

    void setDir(int dir_x, int dir_y) {
        //if (dir_x == 0) {
        //    if (dir_y == 1)
        //        dir = 3;
        //    else
        //        dir = 1;
        //}
        //else {
        //    if (dir_x == 1)
        //        dir = 0;
        //    else
        //        dir = 2;
        //}

        if (dir_x == 0) {
            if (dir_y > 0)
                dir = 3;
            if (dir_y < 0)
                dir = 1;
        }
        else {
            if (dir_x > 0)
                dir = 0;
            if (dir_x < 0)
                dir = 2;
        }
    }

    void setAutoDir(Pair nextPos) {

    }

    void setDirection(float time) {
        switch (dir) {
        case 0:
            dx = speedRun;
            dy = 0;
            break;
        case 1:
            dx = 0;
            dy = -speedRun;
            break;
        case 2:
            dx = -speedRun;
            dy = 0;
            break;
        case 3:
            dx = 0;
            dy = speedRun;
            break;
        }
    }

    void update(float time, bool autoMode) {
        x += dx;
        y += dy;
        characterSprite.setPosition(x, y);
        interactionWithMap();
        getGridPos();
    }

    void interactionWithMap() {
        for (int i = y / PICTURE_RESOLUTION; i < (y + h) / PICTURE_RESOLUTION; i++)
            for (int j = x / PICTURE_RESOLUTION; j < (x + w) / PICTURE_RESOLUTION; j++) {
                if (MAP.Grid[i][j] == '0' || MAP.Grid[i][j] == 'd') {
                    switch (dir) {
                    case 0: x = j * PICTURE_RESOLUTION - w; break;
                    case 1: y = i * PICTURE_RESOLUTION + PICTURE_RESOLUTION; break;
                    case 2: x = j * PICTURE_RESOLUTION + PICTURE_RESOLUTION; break;
                    case 3: y = i * PICTURE_RESOLUTION - h; break;
                    }
                }
            }
    }

    void toMove(float& CurrentFrame, float& time, bool& autoMode) {
        int coordinates[3][3] = {
            {67, 250, 430},
            {25, 210, 400},
            {66, 250, 435}
        };

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 400, 75, 74));
            dir = 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(600, coordinates[1][int(CurrentFrame)], 75, 74));
            dir = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[2][int(CurrentFrame)], 25, 75, 74));
            dir = 3;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 25, 75, 74));
            dir = 0;
        }

        setDirection(time);
        update(time, autoMode);
    }
};

