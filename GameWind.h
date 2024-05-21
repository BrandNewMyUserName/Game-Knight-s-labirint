#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Map.h"
#include "A_Star.h"
#include "observed_area.h"

//const int EXIT_GAME = 1;
//const int PLAY_GAME = 0;
#define PICTURE_RESOLUTION 80

using namespace sf;
using namespace std;


class GameWind { // Rename
public:
    int width_screen, height_screen;
    String WindowName;
    Character character;
    bool autoMode = 0;

    Map MAP = Map();

    Image mapImage;
    Texture mapTexture;
    Sprite s_map;
    String imageLink;

    RenderWindow currentWind;

    GameWind(): currentWind(sf::VideoMode(1920, 1080), "Knight's Labyrinth: Treasure Hunt"), character(/*this->MAP*/) {
        this->width_screen = 1920; //1900
        this->height_screen = 1080; //1050
        this->WindowName = "Knight's Labyrinth: Treasure Hunt";
        imageLink = "map(80x80).jpg";

//Try-Catch
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
        view.reset(FloatRect(0, 0, 800, 450));
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
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                autoMode = 1;
                character.navigation.search(character.x_pos, character.y_pos);
            }

            if (autoMode) {
                character.autoMove(CurrentFrame, time, autoMode);
            }

            if(!autoMode)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                character.toMove(CurrentFrame, time);
                getplayercoordinateforview(character.x, character.y);
 
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
            //character.update(time);
            currentWind.setView(view);//"��������" ������ � ���� sfml
            currentWind.clear(Color(59, 62, 39));


            for (int i = 0; i < HEIGHT_MAP; i++) {
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    if (MAP.Grid[i][j] == ' ')
                        this->s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));                    // ����� 
                    if (MAP.Grid[i][j] == '0')
                        this->s_map.setTextureRect(IntRect(PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // ����
                    if (MAP.Grid[i][j] == 't')
                        this->s_map.setTextureRect(IntRect(3*PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION)); // ���������


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

