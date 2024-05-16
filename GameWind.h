#pragma once
//#include<iostream>
#include <SFML/Graphics.hpp>
#include"Map.h"
#define PICTURE_RESOLUTION 32

using namespace sf;

int OpenGameWindow() {
    sf::RenderWindow gameWindow(sf::VideoMode(1920, 1080), "SFML Page Movement" /*,sf::Style::Fullscreen*/);

    class Character {
    public: float x, y;
          String File;
          Image image;
          Texture texture;

          Character(String Picture_link) {
          
          }

    };

    class Player {
    private: float x, y;
    public:
        float w, h, dx, dy, speed;
        int dir;
        String File;
        Image image;
        Texture texture;
        Sprite sprite;
        Player(String F, float X, float Y, float W, float H) {
            dx = 0; dy = 0; speed = 0; dir = 0;
            File = F;
            w = W; h = H;
            image.loadFromFile("images/" + File);
            image.createMaskFromColor(Color(41, 33, 59));
            texture.loadFromImage(image);
            sprite.setTexture(texture);
            x = X; y = Y;
            sprite.setTextureRect(IntRect(0, 0, w, h));
        }
        void update(float time)
        {
            switch (dir)
            {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed; break;
            case 3: dx = 0; dy = -speed; break;
            }

            x += dx * time;
            y += dy * time;

            speed = 0;
            sprite.setPosition(x, y);
            interactionWithMap();//�������� �������, ���������� �� �������������� � ������
        }


        void interactionWithMap()//�-��� �������������� � ������
        {

            for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������, �������������� � �������,, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
                for (int j = x / 32; j < (x + w) / 32; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
                {
                    if (MAP[i][j] == '0')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
                    {
                        if (dy > 0)//���� �� ��� ����,
                        {
                            y = i * 32 - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
                        }
                        if (dy < 0)
                        {
                            y = i * 32 + 32;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
                        }
                        if (dx > 0)
                        {
                            x = j * 32 - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
                        }
                        if (dx < 0)
                        {
                            x = j * 32 + 32;//���������� ���� �����
                        }
                    }

                    if (MAP[i][j] == 's') { //���� ������ ����� 's' (������)
                        x = 300; y = 300;//����� �� ��������... �������� ������������ �����
                        MAP[i][j] = ' ';//������� ������, ���� ����� �����. ����� � �� �������, ������.
                    }
                }
        }


        float getplayercoordinateX() {
            return x;
        }
        float getplayercoordinateY() {
            return y;
        }

    };

    //��������� ������
    Image knight;
    if (!knight.loadFromFile("pictures/Knight_spikes.png")) {
        return EXIT_FAILURE;
    };
    Texture knightTexture;
    knightTexture.loadFromImage(knight);

    Sprite knightSprite;
    knightSprite.setTexture(knightTexture);
    knightSprite.setTextureRect(IntRect(8, 15, 180, 112));
    knightSprite.setPosition(250, 250);

    //��������� �����
    Image mapImage;
    if (!mapImage.loadFromFile("pictures/map.png")) {
        return EXIT_FAILURE;
    };
    Texture mapTexture;
    mapTexture.loadFromImage(mapImage);
    Sprite s_map;
    s_map.setTexture(mapTexture);

    Clock clock;

    // �������� ���� ���������
    while (gameWindow.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        float CurrentFrame = 0;
        sf::Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }
        }

        // �����ֲ� ���� ������ ϲ� ��� ���������� ���²�
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            int xTexture = 0;
            xTexture = (int)knightSprite.getPosition().y % 3;
            switch (xTexture) {
            case 0:
                knightSprite.setTextureRect(IntRect(600, 25, 75, 74));
                break;

            case 1:
                knightSprite.setTextureRect(IntRect(600, 210, 75, 74));
                break;

            case 2:
                knightSprite.setTextureRect(IntRect(600, 400, 75, 74));
                break;
            }
            
            knightSprite.move(0, -0.1 * time);
            //position.y -= 0.1f * time;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            int xTexture = 0;
            xTexture = (int)knightSprite.getPosition().y % 3;
            switch (xTexture) {
            case 0:
                knightSprite.setTextureRect(IntRect(66, 210, 75, 74));
                break;

            case 1:
                knightSprite.setTextureRect(IntRect(250, 210, 75, 74));
                break;

            case 2:
                knightSprite.setTextureRect(IntRect(435, 210, 75, 74));
                break;
            }
            knightSprite.move(0, 0.1 * time);
            //position.y += 0.1f*time;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            int xTexture = 0;
            xTexture = (int)knightSprite.getPosition().x % 3;
            switch (xTexture) {
            case 0:
                knightSprite.setTextureRect(IntRect(67, 400, 75, 74));
                break;

            case 1:
                knightSprite.setTextureRect(IntRect(250, 400, 75, 74));
                break;

            case 2:
                knightSprite.setTextureRect(IntRect(435, 400, 75, 74));
                break;
            }
            knightSprite.move(-0.1 * time, 0);
           // position.x -= 0.1f*time;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            int xTexture = 0;
            xTexture = (int)knightSprite.getPosition().x  % 3;
            switch (xTexture) {
            case 0:
                knightSprite.setTextureRect(IntRect(67, 25, 75, 74));
                break;
            
            case 1:
                knightSprite.setTextureRect(IntRect(250, 25, 75, 74));
                break;

            case 2:
                knightSprite.setTextureRect(IntRect(435, 25, 75, 74));
                break;
            }

            knightSprite.move(0.1 * time, 0);
           // position.x += 0.1f* time;
        }

        
        //if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        //        CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
        //        if (CurrentFrame > 3) 
        //            CurrentFrame -= 3; //���� ������ � �������� ����� - ������������ �����.
        //        knightSprite.setTextureRect(IntRect(180 * int(CurrentFrame), 15, 180, 112)); 
        //        //knightSprite.setTextureRect(IntRect(8, 15, 100, 112));
        //        knightSprite.move(0.1 * time, 0);//���������� ���� �������� ��������� ������
        //}


        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            gameWindow.close();
            return EXIT_FAILURE;
        }


        gameWindow.clear();

        //��������� �����
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (MAP[i][j] == '0')  s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION)); //���� ��������� ������ ������, �� ������ 1� ���������
                if (MAP[i][j] == '1')  s_map.setTextureRect(IntRect(PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));//���� ��������� ������ s, �� ������ 2� ���������
                //if ((Map[i][j] == )) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������


                s_map.setPosition(j * PICTURE_RESOLUTION, i * PICTURE_RESOLUTION);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

                gameWindow.draw(s_map);//������ ���������� �� �����
            }


        // ���������� ������� �������
        //knightSprite.setPosition(position);

        // ������� ������ � ��������� �������
        
        gameWindow.draw(knightSprite);
        gameWindow.display();
    }

    return EXIT_SUCCESS;
}