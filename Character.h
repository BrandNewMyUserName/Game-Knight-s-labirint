#pragma once
#include"A_star.h"
#include"Map.h"
#include"observed_area.h"

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

        //Try-Catch
          /*        this->characterImage;
                  try {
                      if (!this->characterImage.loadFromFile("pictures/" + this->Picture_name)) {
                          throw "Unable to find a character image";
                      }
                  }
                  catch (const char* exception)
                  {
                      cerr << "Error: " << exception << '\n';
                  }*/

        this->characterTexture.loadFromImage(this->characterImage);
        this->characterSprite.setTexture(this->characterTexture);
        this->characterSprite.setTextureRect(IntRect(8, 15, 180, 112));
        setMapPos();
        this->characterSprite.setPosition(x, y);
    }


    void autoMove(float& CurrentFrame, float& time, bool& autoMode) {
        if (!navigation.path.empty()) {
            auto nextPos = navigation.path.front();

            //if ((x - nextPos.first * PICTURE_RESOLUTION) == 0 && (y - nextPos.second * PICTURE_RESOLUTION) == 0)
            //    navigation.path.erase(navigation.path.begin());

            if ((x - nextPos.first * PICTURE_RESOLUTION) == 0 && (y - nextPos.second * PICTURE_RESOLUTION) == 0)
                navigation.path.erase(navigation.path.begin());

            int dir_x = nextPos.first - x_pos;
            int dir_y = nextPos.second - y_pos;

            // Set the direction based on the calculated direction
            setDir(dir_x, dir_y);

            // Update the character's animation frame
            autoChangeSpike(CurrentFrame, time);

            // Update the character's position
            setDirection(time);
            update(time, autoMode);

            // Remove the reached position from the path
            //if(floor(x_pos) == nextPos.first && floor(y_pos) == nextPos.second)
            //  navigation.path.erase(navigation.path.begin());

        }
        else {
            autoMode = 0;
        }
    }


    void autoChangeSpike(float& CurrentFrame, float& time) {
        //int coordinates[3][3] = {
        //    {67, 250, 430},
        //    {25, 210, 400},
        //    {66, 250, 435}
        //};

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



    /*
    void autoMove(float& CurrentFrame, float &time, bool& autoMode) {
          int dir_x, dir_y;
          if (!navigation.path.empty()) {
              auto p = navigation.path[0];
              dir_x = p.first - x_pos;
              dir_y = p.second - y_pos;
              setDir(dir_x, dir_y);
              autoChangeSpike(CurrentFrame, time);
              update(time);
              navigation.path.erase(navigation.path.begin());
          }
          else
              autoMode = 1;
    }
    void autoChangeSpike(float &CurrentFrame, float& time) {
        int coordinates[3][3] = {
          {67, 250, 430},
          {25, 210, 400},
          {66, 250, 435}
        };
        switch (dir) {
        case 0:
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 25, 75, 74));
            break;
        case 1:
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(600, coordinates[1][int(CurrentFrame)], 75, 74));
            break;
        case 2:
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 400, 75, 74));
            break;
        case 3:
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[2][int(CurrentFrame)], 210, 75, 74));
            break;
        }
        setDirection(time);
    }
    */

    //void setInCenter() {
    //    characterSprite.setPosition(x_pos * PICTURE_RESOLUTION + PICTURE_RESOLUTION / 2, y * PICTURE_RESOLUTION);

    //}

    void placeInAngle() {
        characterSprite.setPosition(y_pos * PICTURE_RESOLUTION, x_pos * PICTURE_RESOLUTION);

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
        //if (dir_x == 0 && dir_y == 0)
        //    return;

       /* if (dir_x == 0) {
            if (dir_y == 1)
                dir = 3;
            else {
                if (dir_y == -1)
                    dir = 1;
            }
        }
        else {
            if (dir_x == 1)
                dir = 0;
            else {
                if (dir_x == -1)
                    dir = 2;
            }
        }*/

        if (dir_x == 0) {
            if (dir_y == 1)
                dir = 3;
            else
                dir = 1;
        }
        else {
            if (dir_x == 1)
                dir = 0;
            else
                dir = 2;
        }
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

    void interactionWithMap()
    {
        for (int i = y / PICTURE_RESOLUTION; i < (y + h) / PICTURE_RESOLUTION; i++)//проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера PICTURE_RESOLUTION*PICTURE_RESOLUTION, которые мы окрашивали в 9 уроке. про условия читайте ниже.
            for (int j = x / PICTURE_RESOLUTION; j < (x + w) / PICTURE_RESOLUTION; j++)//икс делим на PICTURE_RESOLUTION, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера PICTURE_RESOLUTION*PICTURE_RESOLUTION, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / PICTURE_RESOLUTION - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
            {
                if (MAP.Grid[i][j] == '0' || MAP.Grid[i][j] == 'd')
                {
                    switch (dir) {
                    case 0: x = j * PICTURE_RESOLUTION - w; break;
                    case 1: y = i * PICTURE_RESOLUTION + PICTURE_RESOLUTION; break;
                    case 2: x = j * PICTURE_RESOLUTION + PICTURE_RESOLUTION; break;
                    case 3: y = i * PICTURE_RESOLUTION - h; break;
                    }
                }
                /*                 if (MAP.Grid[i][j] == '0')
                                     characterSprite.setPosition(500, 500);
                                     if (MAP.Grid[i][j] == 's') { //если символ равен 's' (камень)
                                         x = 300; y = 300;//какое то действие... например телепортация героя
                                         MAP.Grid[i][j] = ' ';//убираем камень, типа взяли бонус. можем и не убирать, кстати.
                                     }
                  */
            }
    }

    //void update(float time) {
    //    switch (dir) {
    //    case 0: dx = speedRun*time; dy = 0; break;
    //    case 1: dx = -speedRun * time; dy = 0; break;
    //    case 2: dx = 0; dy = speedRun * time; break;
    //    case 3: dx = 0; dy = -speedRun * time; break;
    //    }

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
            characterSprite.setTextureRect(IntRect(coordinates[2][int(CurrentFrame)], 210, 75, 74));
            dir = 3;
        }
        if ((sf::Keyboard::isKeyPressed(Keyboard::D))) {
            CurrentFrame += speedMove * time;
            if (CurrentFrame > 3)
                CurrentFrame -= 3;
            characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 25, 75, 74));
            dir = 0;
        }

        setDirection(time);
        update(time, autoMode);



        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        //    CurrentFrame += speedMove * time;
        //    if (CurrentFrame > 3)
        //        CurrentFrame -= 3;
        //    characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 400, 75, 74));
        //    characterSprite.move(-speedRun * time, 0);
        //    dir = 2;
        //}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        //    CurrentFrame += speedMove * time;
        //    if (CurrentFrame > 3)
        //        CurrentFrame -= 3;
        //    characterSprite.setTextureRect(IntRect(600, coordinates[1][int(CurrentFrame)], 75, 74));
        //    characterSprite.move(0, -speedRun * time);
        //    dir = 1;
        //}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        //    CurrentFrame += speedMove * time;
        //    if (CurrentFrame > 3)
        //        CurrentFrame -= 3;
        //    characterSprite.setTextureRect(IntRect(coordinates[2][int(CurrentFrame)], 210, 75, 74));
        //    characterSprite.move(0, speedRun * time);
        //    dir = 3;
        //}
        //if ((sf::Keyboard::isKeyPressed(Keyboard::D))) {
        //    CurrentFrame += speedMove * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив speedMove можно изменить скорость анимации
        //    if (CurrentFrame > 3)
        //        CurrentFrame -= 3;
        //    characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 25, 75, 74));
        //    characterSprite.move(speedRun * time, 0);
        //    dir = 0;
        //}
    }

};