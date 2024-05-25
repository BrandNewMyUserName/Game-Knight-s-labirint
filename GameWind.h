#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Map.h"
#include "A_Star.h"

//#define PICTURE_RESOLUTION 80

using namespace sf;
using namespace std;


class GameWind { // Rename
private:
    Character character;

public:
    int width_screen, height_screen;
    String WindowName;

    bool autoMode = 0, IsTreasureOpened = 0;
    Map MAP;
    //Character 
    View view;
    Image mapImage;
    Texture mapTexture;
    Sprite s_map;
    String imageLink;

    RenderWindow currentWind;

    GameWind() : width_screen(1920 /*1900*/), height_screen(1080 /*1050*/), WindowName("Knight's Labyrinth: Treasure Hunt"), imageLink("map(80x80).jpg") {
        Character character(MAP);
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

    void getplayercoordinateforview(float x, float y) { 
        view.setCenter(x + 100, y); 

    }

    void drawMap() {

       // s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));
        //s_map.setPosition(0 * PICTURE_RESOLUTION, 0 * PICTURE_RESOLUTION);

        currentWind.draw(this->s_map);

        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (MAP.Grid[i][j] == ' ')
                    this->s_map.setTextureRect(IntRect(0 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // Шляхи 
                if (MAP.Grid[i][j] == '0')
                    this->s_map.setTextureRect(IntRect(1 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // Стіни
                if (MAP.Grid[i][j] == 'c')
                    this->s_map.setTextureRect(IntRect(2 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // Золото
                if (MAP.Grid[i][j] == 't')
                    this->s_map.setTextureRect(IntRect(3 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // Скарбниця
                if (MAP.Grid[i][j] == 'k')
                    this->s_map.setTextureRect(IntRect(4 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // Ключ
                if (MAP.Grid[i][j] == 'd')
                    this->s_map.setTextureRect(IntRect(5 * PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));   // Двері

                // Розміщення поля згідно позиції
                s_map.setPosition(j * PICTURE_RESOLUTION, i * PICTURE_RESOLUTION);
                currentWind.draw(s_map);
            }
        }
    }

    int run() {
        view.reset(FloatRect(character.x, character.y, 800, 450));
        getplayercoordinateforview(character.x, character.y);

        Font font;
        font.loadFromFile("Fonts/troika.otf");
        Text scoreValue(" ", font, 100);
        scoreValue.setStyle(Text::Italic);
        scoreValue.setFillColor(Color::Color(59, 62, 39));

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

            if (autoMode) {
                clock.restart();
                time = time / 1200;
                character.autoMove(CurrentFrame, time, autoMode);
                getplayercoordinateforview(character.x, character.y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                autoMode = 1;
                character.layPath();
                character.placeInAngle();

            }

            if (!autoMode) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    character.toMove(CurrentFrame, time, autoMode);
                    getplayercoordinateforview(character.x, character.y);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                currentWind.close();
            }

            currentWind.setView(view);
            currentWind.clear(Color(59, 62, 39));



            drawMap();

            

            std::ostringstream playerScoreString;
            std::ostringstream Pos_X_str, Pos_Y_str;
            Pos_X_str << character.x_pos;
            Pos_Y_str << character.y_pos;
            scoreValue.setString("Pos_x: " + Pos_X_str.str() + "Pos_y: " + Pos_Y_str.str());
            scoreValue.setPosition(view.getCenter().x + 250, view.getCenter().y - 200);
            scoreValue.setCharacterSize(12);
            
            currentWind.draw(scoreValue);
            currentWind.draw(character.characterSprite);
            currentWind.display();


        }
        currentWind.close();
        return EXIT_SUCCESS;


    }

};

