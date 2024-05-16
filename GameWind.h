#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
//#include "Map.h"

//const int EXIT_GAME = 1;
//const int PLAY_GAME = 0;
#define PICTURE_RESOLUTION 32

using namespace sf;
using namespace std;


class Character {
public: float x, y, speed;
      String Picture_name;
      Image characterImage;
      Texture characterTexture;
      Sprite characterSprite;

      Character() {
          this->x = 250;
          this->y = 250;
          Picture_name = "Knight_spikes.png";

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

};

class GameWind { // Rename
public:
    int width_screen, height_screen;
    String WindowName;
    Character character;

    //Map MAP;

    Image mapImage;
    Texture mapTexture;
    Sprite s_map;
    String imageLink;

    RenderWindow currentWind;

    GameWind(): currentWind(sf::VideoMode(1900, 1050), "Knight's Labyrinth: Treasure Hunt"), character() /*, MAP()*/ {
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
        s_map.setTexture(mapTexture);
    }


    int run() {
        //currentWind(sf::VideoMode(1900, 1050), "Knight's Labyrinth: Treasure Hunt");
        //currentWind.create(VideoMode(this->width_screen, this->height_screen), this->WindowName /*,sf::Style::Fullscreen*/);
        int nextState;
        Clock clock;

        while (currentWind.isOpen()) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time /= 800;
            float CurrentFrame = 0;
            sf::Event event;

            while (currentWind.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    currentWind.close();
                    //nextState = 1;
                }
            }

            // ЕМУЛЯЦІЯ РУХУ ЛИЦАРЯ ПІД ЧАС НАТИСКАННЯ КЛАВІШ
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
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

            // ПОКРАЩЕНЕ КЕРУВАННЯ АКТОРОМ

            //if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            //        CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            //        if (CurrentFrame > 3) 
            //            CurrentFrame -= 3; //если пришли к третьему кадру - откидываемся назад.
            //        knightSprite.setTextureRect(IntRect(180 * int(CurrentFrame), 15, 180, 112)); 
            //        //knightSprite.setTextureRect(IntRect(8, 15, 100, 112));
            //        knightSprite.move(0.1 * time, 0);//происходит само движение персонажа вправо
            //}


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                currentWind.close();
                //nextState = 1;
            }

            currentWind.clear();
            currentWind.draw(character.characterSprite);
            currentWind.display();

            //void draw();

            //for (int i = 0; i < HEIGHT_MAP; i++) {
            //    for (int j = 0; j < WIDTH_MAP; j++)
            //    {
            //        if (MAP.Grid[i][j] == '0')
            //            this->s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION)); //если встретили символ пробел, то рисуем 1й квадратик
            //        if (MAP.Grid[i][j] == '1')
            //            s_map.setTextureRect(IntRect(PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));//если встретили символ s, то рисуем 2й квадратик
            //        //if ((Map[i][j] == )) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


            //        s_map.setPosition(j * PICTURE_RESOLUTION, i * PICTURE_RESOLUTION);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

            //        currentWind.draw(s_map);//рисуем квадратики на экран
            //    }

            //}


        }
        //return nextState;
        currentWind.close();
        return EXIT_SUCCESS;


    }


    void draw() {



    }



};

