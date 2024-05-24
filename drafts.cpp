// Old MainWind class

/*#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Button {
public:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::White);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + (width - text.getLocalBounds().width) / 2, y + (height - text.getLocalBounds().height) / 2);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(sf::RenderWindow& window) {
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        if (shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            return true;
        }
        return false;
    }
};

class MainWindow {
public:
    RenderWindow mainWind;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Font font;
    Button closeButton;
    Button gameButton;

    int nextState = -1;

public:
    MainWindow() :
    // mainWind(sf::VideoMode(1900, 1050), "MAIN MENU"), 
    closeButton(400, 100, 200, 50, "Вийти", font), gameButton(500, 200, 200, 50, "Почати гру", font) {

        //try {
        //    if (!backgroundTexture.loadFromFile("pictures/MainWind-background.png")) {
        //        int a = -1;
        //        throw a;
        //            //"Unable to find an map image";
        //    }
        //}
        //catch (int a) {
        //    cerr << "Error: " << a;
        //}

        backgroundTexture.loadFromFile("pictures/MainWind-background.png");

        backgroundSprite.setTexture(backgroundTexture);

        font.loadFromFile("Fonts/troika.otf"); // Load font

        closeButton = Button(400, 100, 200, 50, "Вийти", font);
        gameButton = Button(500, 200, 200, 50, "Почати гру", font);
    }


    void closeWindow() {
        mainWind.close();
    }

    int run() {
        mainWind.create(sf::VideoMode(1900, 1050), "MAIN MENU");


        while (mainWind.isOpen()) {

            Event event;

            while (mainWind.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    closeWindow();
                    return EXIT_SUCCESS;

                    nextState = 1;
                    break;
                    mainWind.close();
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (closeButton.isClicked(mainWind)) {
                        closeWindow();
                        return EXIT_SUCCESS;
                        //();
                        nextState = 0;
                        break;//TODO
                    }
                    if (gameButton.isClicked(mainWind)) {
                        closeWindow();
                        return EXIT_FAILURE;
                        nextState = EXIT_FAILURE;
                        break;
                        return 1; //TODO
                    }
                }
            }

            mainWind.clear();

            backgroundSprite.setScale(mainWind.getSize().x / backgroundSprite.getLocalBounds().width,
                mainWind.getSize().y / backgroundSprite.getLocalBounds().height);
            mainWind.draw(backgroundSprite);
            mainWind.draw(backgroundSprite);
            closeButton.draw(mainWind);
            gameButton.draw(mainWind);
            mainWind.display();
        }

        closeWindow();
        return nextState; //TODO
    }
};
 */


