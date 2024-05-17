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

      void interactionWithMap()//�-��� �������������� � ������
      {

          for (int i = y / PICTURE_RESOLUTION; i < (y + h) / PICTURE_RESOLUTION; i++)//���������� �� ��������, �������������� � �������, �� ���� �� ���� ����������� ������� PICTURE_RESOLUTION*PICTURE_RESOLUTION, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
              for (int j = x / PICTURE_RESOLUTION; j < (x + w) / PICTURE_RESOLUTION; j++)//��� ����� �� PICTURE_RESOLUTION, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� PICTURE_RESOLUTION*PICTURE_RESOLUTION, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / PICTURE_RESOLUTION - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
              {
                  if (MAP.Grid[i][j] == '0')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
                  {
                      if (dy > 0)//���� �� ��� ����,
                      {
                          y = i * PICTURE_RESOLUTION - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
                      }
                      if (dy < 0)
                      {
                          y = i * PICTURE_RESOLUTION + PICTURE_RESOLUTION;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
                      }
                      if (dx > 0)
                      {
                          x = j * PICTURE_RESOLUTION - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
                      }
                      if (dx < 0)
                      {
                          x = j * PICTURE_RESOLUTION + PICTURE_RESOLUTION;//���������� ���� �����
                      }
                  }

                  //if (MAP.Grid[i][j] == 's') { //���� ������ ����� 's' (������)
                  //    x = 300; y = 300;//����� �� ��������... �������� ������������ �����
                  //    MAP.Grid[i][j] = ' ';//������� ������, ���� ����� �����. ����� � �� �������, ������.
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
              CurrentFrame += speedMove * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� speedMove ����� �������� �������� ��������
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
                



            // �����ֲ� ���� ������ ϲ� ��� ���������� ���²�
/*
            int x_coord[] = { 67, 250, 435 };
            if ((Keyboard::isKeyPressed(Keyboard::D))) {
                    CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
                    if (CurrentFrame > 3) 
                        CurrentFrame -= 3; 
                    character.characterSprite.setTextureRect(IntRect(x_coord[int(CurrentFrame)], 15, 180, 112));
                    character.characterSprite.move(0.1 * time, 0);
            }

            if ((Keyboard::isKeyPressed(Keyboard::D))) {

                CurrentFrame += 100 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
                if (i > 2)
                    i = 0; //���� ������ � �������� ����� - ������������ �����.
                character.characterSprite.setTextureRect(IntRect(x_coord[i], 25, 75, 74));
                character.characterSprite.move(0.1 * time, 0);
                ++i;
                character.dx = 2;
                character.dx = 0;

            }

            if ((Keyboard::isKeyPressed(Keyboard::D))) {

                CurrentFrame += 100 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
                if (i > 2)
                    i = 0; //���� ������ � �������� ����� - ������������ �����.
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
                        this->s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION)); //����
                    if (MAP.Grid[i][j] == ' ')
                        this->s_map.setTextureRect(IntRect(PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));// �����
                    //if ((Map[i][j] == )) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������


                    this->s_map.setPosition(j * PICTURE_RESOLUTION, i * PICTURE_RESOLUTION);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

                    currentWind.draw(this->s_map);//������ ���������� �� �����
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

