#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Map.h"
#include "A_Star.h"
#include "observed_area.h"

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

    GameWind() : width_screen(1920 /*1900*/), height_screen(1080 /*1050*/), WindowName("Knight's Labyrinth: Treasure Hunt"), imageLink("map(80x80).jpg") {

        currentWind.create(VideoMode(width_screen, height_screen), WindowName);

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
        view.reset(FloatRect(character.x, character.y, 800, 450));
        getplayercoordinateforview(character.x, character.y);

        Font font;
        font.loadFromFile("C:\\Users\\User\\Desktop\\University\\2 курс 2 семестр\\ урсова робота\\ артинки\\Ўрифт\\static\\OpenSans_Condensed - Bold.ttf");
        Text scoreValue(" ", font, 100);
        scoreValue.setStyle(Text::Bold);
        scoreValue.setFillColor(Color::Red);

        float CurrentFrame = 0;
        Clock clock;

        while (currentWind.isOpen()) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 1200;

            sf::Event event;

            while (currentWind.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    currentWind.close();
                }
            }


            if (autoMode && character.navigation.foundDest) {
                clock.restart();
                time = time / 1200;
                character.autoMove(CurrentFrame, time, autoMode);
                getplayercoordinateforview(character.x, character.y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                autoMode = 1;
                character.navigation.search(character.x_pos, character.y_pos);


                //auto nextPos = character.navigation.path.front();
                //int dir_x = nextPos.first - character.x_pos;
                //int dir_y = nextPos.second - character.y_pos;
                //setDir(dir_x, dir_y);
                character.placeInAngle();

            }




            if (!autoMode) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    character.toMove(CurrentFrame, time, autoMode);
                    getplayercoordinateforview(character.x, character.y);
                }
            }





            // ≈ћ”Ћя÷≤я –”’” Ћ»÷ј–я ѕ≤ƒ „ј— Ќј“»— јЌЌя  Ћј¬≤Ў
/*
            int x_coord[] = { 67, 250, 435 };
            if ((Keyboard::isKeyPressed(Keyboard::D))) {
                    CurrentFrame += 0.005 * time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до трех суммиру€ произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                    if (CurrentFrame > 3)
                        CurrentFrame -= 3;
                    character.characterSprite.setTextureRect(IntRect(x_coord[int(CurrentFrame)], 15, 180, 112));
                    character.characterSprite.move(0.1 * time, 0);
            }

            if ((Keyboard::isKeyPressed(Keyboard::D))) {

                CurrentFrame += 100 * time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до трех суммиру€ произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                if (i > 2)
                    i = 0; //если пришли к третьему кадру - откидываемс€ назад.
                character.characterSprite.setTextureRect(IntRect(x_coord[i], 25, 75, 74));
                character.characterSprite.move(0.1 * time, 0);
                ++i;
                character.dx = 2;
                character.dx = 0;

            }

            if ((Keyboard::isKeyPressed(Keyboard::D))) {

                CurrentFrame += 100 * time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до трех суммиру€ произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                if (i > 2)
                    i = 0; //если пришли к третьему кадру - откидываемс€ назад.
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
                currentWind.close();
                //nextState = 1;
            }
            //character.update(time);
            currentWind.setView(view);//"оживл€ем" камеру в окне sfml
            currentWind.clear(Color(59, 62, 39));

            this->s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));
            this->s_map.setPosition(0 * PICTURE_RESOLUTION, 0 * PICTURE_RESOLUTION);//по сути раскидывает квадратики, превраща€ в карту. то есть задает каждому из них позицию. если убрать, то вс€ карта нарисуетс€ в одном квадрате 32*32 и мы увидим один квадрат
            currentWind.draw(this->s_map);

            for (int i = 0; i < HEIGHT_MAP; i++) {
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    if (MAP.Grid[i][j] == ' ')
                        this->s_map.setTextureRect(IntRect(0 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // Ўл€хи 
                    if (MAP.Grid[i][j] == '0')
                        this->s_map.setTextureRect(IntRect(1 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // —т≥ни
                    if (MAP.Grid[i][j] == 'c')
                        this->s_map.setTextureRect(IntRect(2 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // «олото
                    if (MAP.Grid[i][j] == 't')
                        this->s_map.setTextureRect(IntRect(3 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // —карбниц€
                    if (MAP.Grid[i][j] == 'k')
                        this->s_map.setTextureRect(IntRect(4 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // —карбниц€
                    if (MAP.Grid[i][j] == 'd')
                        this->s_map.setTextureRect(IntRect(5 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // —карбниц€

                    this->s_map.setPosition(j * PICTURE_RESOLUTION, i * PICTURE_RESOLUTION);//по сути раскидывает квадратики, превраща€ в карту. то есть задает каждому из них позицию. если убрать, то вс€ карта нарисуетс€ в одном квадрате 32*32 и мы увидим один квадрат

                    currentWind.draw(this->s_map);//рисуем квадратики на экран
                }
            }

            std::ostringstream playerScoreString;
            std::ostringstream Pos_X_str, Pos_Y_str;
            Pos_X_str << character.x_pos;
            Pos_Y_str << character.y_pos;
            scoreValue.setString("Pos_x: " + Pos_X_str.str());
            scoreValue.setPosition(view.getCenter().x, view.getCenter().y);
            currentWind.draw(scoreValue);
            currentWind.draw(character.characterSprite);
            currentWind.display();


        }
        currentWind.close();
        return EXIT_SUCCESS;


    }

};

