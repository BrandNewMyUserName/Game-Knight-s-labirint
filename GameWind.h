#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"

//const int EXIT_GAME = 1;
//const int PLAY_GAME = 0;
#define PICTURE_RESOLUTION 32

using namespace sf;
using namespace std;


class Character {
public: float x, y, speedMove, speedRun, h, w;
        int dx, dy, dir;
      String Picture_name;
      Image characterImage;
      Texture characterTexture;
      Sprite characterSprite;
      Map MAP;

      Character(Map MAP): x(250), y(250), h(74), w(75), speedMove(0.05), speedRun(0.1), dir(0), Picture_name("Knight_spikes.png"){
          this->x = 500;
          this->y = 500;
          h = 74;
          w = 75;
          Picture_name = "Knight_spikes.png";
          this->MAP = MAP;

          this->characterImage.loadFromFile("pictures/" + this->Picture_name);

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
       
          this->characterSprite.setPosition(this->x, this->y);
      }

      float getX() {
          return x;
      }

      float getY() {
          return y;
      }

      //(Keyboard::isKeyPressed(Keyboard::D)

      //void move(Key Key) {
      //    switch (Keyboard::Key) {
      //    case A:

      //    }
      //
      //}


      void setDirection() {
          switch (this->dir) {
          case 0:
              dx = -1;
              dy = 0;
              break;
          case 1:
              dx = 0;
              dy = -1;
              break;
          case 2:
              dx = 1;
              dy = 0;
              break;
          case 3:
              dx = 0;
              dy = 1;
              break;
          }
      }

      void interactionWithMap()//ф-ция взаимодействия с картой
      {

          for (int i = y / PICTURE_RESOLUTION; i < (y + h) / PICTURE_RESOLUTION; i++)//проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера PICTURE_RESOLUTION*PICTURE_RESOLUTION, которые мы окрашивали в 9 уроке. про условия читайте ниже.
              for (int j = x / PICTURE_RESOLUTION; j < (x + w) / PICTURE_RESOLUTION; j++)//икс делим на PICTURE_RESOLUTION, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера PICTURE_RESOLUTION*PICTURE_RESOLUTION, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / PICTURE_RESOLUTION - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
              {
                  if (MAP.Grid[i][j] == '0')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
                  {
                      if (dy > 0)//если мы шли вниз,
                      {
                          y = i * PICTURE_RESOLUTION - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
                      }
                      if (dy < 0)
                      {
                          y = i * PICTURE_RESOLUTION + PICTURE_RESOLUTION;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
                      }
                      if (dx > 0)
                      {
                          x = j * PICTURE_RESOLUTION - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
                      }
                      if (dx < 0)
                      {
                          x = j * PICTURE_RESOLUTION + PICTURE_RESOLUTION;//аналогично идем влево
                      }
                  }

                  //if (MAP.Grid[i][j] == 's') { //если символ равен 's' (камень)
                  //    x = 300; y = 300;//какое то действие... например телепортация героя
                  //    MAP.Grid[i][j] = ' ';//убираем камень, типа взяли бонус. можем и не убирать, кстати.
                  //}
              }
      }

      void toMove(float& CurrentFrame, float& time) {

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
              characterSprite.move(-speedRun * time, 0);
              dir = 2;

          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

              CurrentFrame += speedMove * time;
              if (CurrentFrame > 3)
                  CurrentFrame -= 3;
              characterSprite.setTextureRect(IntRect(600, coordinates[1][int(CurrentFrame)], 75, 74));
              characterSprite.move(0, -speedRun * time);
              dir = 1;
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

              CurrentFrame += speedMove * time;
              if (CurrentFrame > 3)
                  CurrentFrame -= 3;
              characterSprite.setTextureRect(IntRect(coordinates[2][int(CurrentFrame)], 210, 75, 74));
              characterSprite.move(0, speedRun * time);
              dir = 3;

          }
          if ((sf::Keyboard::isKeyPressed(Keyboard::D))) {
              CurrentFrame += speedMove * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив speedMove можно изменить скорость анимации
              if (CurrentFrame > 3)
                  CurrentFrame -= 3;
              characterSprite.setTextureRect(IntRect(coordinates[0][int(CurrentFrame)], 25, 180, 112));
              characterSprite.move(speedRun * time, 0);
              dir = 0;
          }
      }

};

class GameWind { // Rename
public:
    int width_screen, height_screen;
    String WindowName;
    Character character;

    Map MAP;

    Image mapImage;
    Texture mapTexture;
    Sprite s_map;
    String imageLink;

    RenderWindow currentWind;

    GameWind(): currentWind(sf::VideoMode(1900, 1050), "Knight's Labyrinth: Treasure Hunt"), MAP(), character(this->MAP) {
        this->width_screen = 1920;
        this->height_screen = 1080;
        this->WindowName = "Knight's Labyrinth: Treasure Hunt";
        imageLink = "map.png";


  /*      try {
            if (!mapImage.loadFromFile("pictures/" + imageLink)) {
                throw "Unable to find an map image";
            }
        }
        catch (const char* exception)
        {
            cerr << "Error: " << exception << '\n';
        }*/

        mapImage.loadFromFile("pictures/" + imageLink);
        mapTexture.loadFromImage(mapImage);
        this->s_map.setTexture(mapTexture);
    }


    int run() {
        //currentWind(sf::VideoMode(1900, 1050), "Knight's Labyrinth: Treasure Hunt");
        //currentWind.create(VideoMode(this->width_screen, this->height_screen), this->WindowName /*,sf::Style::Fullscreen*/);
        int nextState;
        float CurrentFrame = 0;
        Clock clock;

        while (currentWind.isOpen()) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time/ 1200;
            
            sf::Event event;

            while (currentWind.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    currentWind.close();
                    //nextState = 1;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                character.toMove(CurrentFrame, time);
                character.setDirection();
                character.interactionWithMap();
            }
                



            // ЕМУЛЯЦІЯ РУХУ ЛИЦАРЯ ПІД ЧАС НАТИСКАННЯ КЛАВІШ
/*
            int x_coord[] = { 67, 250, 435 };
            if ((Keyboard::isKeyPressed(Keyboard::D))) {
                    CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                    if (CurrentFrame > 3) 
                        CurrentFrame -= 3; 
                    character.characterSprite.setTextureRect(IntRect(x_coord[int(CurrentFrame)], 15, 180, 112));
                    character.characterSprite.move(0.1 * time, 0);
            }

            if ((Keyboard::isKeyPressed(Keyboard::D))) {

                CurrentFrame += 100 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                if (i > 2)
                    i = 0; //если пришли к третьему кадру - откидываемся назад.
                character.characterSprite.setTextureRect(IntRect(x_coord[i], 25, 75, 74));
                character.characterSprite.move(0.1 * time, 0);
                ++i;
                character.dx = 2;
                character.dx = 0;

            }

            if ((Keyboard::isKeyPressed(Keyboard::D))) {

                CurrentFrame += 100 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                if (i > 2)
                    i = 0; //если пришли к третьему кадру - откидываемся назад.
                character.characterSprite.setTextureRect(IntRect(x_coord[i], 25, 75, 74));
                character.characterSprite.move(0.1 * time, 0);
                ++i;
                character.dx = 2;
                character.dx = 0;

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().y % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(600, 25, 75, 74));
                    
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(600, 210, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(600, 400, 75, 74));
                    break;
                }

                character.characterSprite.move(0, -0.1 * time);
                //position.y -= 0.1f * time;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().y % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(66, 210, 75, 74));
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(250, 210, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(435, 210, 75, 74));
                    break;
                }
                character.characterSprite.move(0, 0.1 * time);
                //position.y += 0.1f*time;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().x % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(67, 400, 75, 74));
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(250, 400, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(435, 400, 75, 74));
                    break;
                }
                character.characterSprite.move(-0.1 * time, 0);
                // position.x -= 0.1f*time;
            }
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().x % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(67, 25, 75, 74));
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(250, 25, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(435, 25, 75, 74));
                    break;
                }

                character.characterSprite.move(0.1 * time, 0);
                // position.x += 0.1f* time;
            }
*/

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                break;
                currentWind.close();
                //nextState = 1;
            }

            currentWind.clear();


            //void draw();

            for (int i = 0; i < HEIGHT_MAP; i++) {
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    if (MAP.Grid[i][j] == '0')
                        this->s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION)); //Стіни
                    if (MAP.Grid[i][j] == ' ')
                        this->s_map.setTextureRect(IntRect(PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));// Шляхи
                    //if ((Map[i][j] == )) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


                    this->s_map.setPosition(j * PICTURE_RESOLUTION, i * PICTURE_RESOLUTION);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                    currentWind.draw(this->s_map);//рисуем квадратики на экран
                }
            }
            currentWind.draw(character.characterSprite);
            currentWind.display();


        }
        //return nextState;
        currentWind.close();
        return EXIT_SUCCESS;


    }


    void draw() {



    }



};

