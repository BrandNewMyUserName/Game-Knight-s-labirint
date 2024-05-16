#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//class MainWindow {
//public:
//
//    static int CreateMainWindow() {
//        // Создание окна для главной страницы
// 
//        sf::RenderWindow mainWindow(sf::VideoMode(1900, 1050), "Knight's Labyrinth: Treasure Hunt" /*, Style::Fullscreen*/);
//        //RenderWindow h()
//
//        // Загрузка фона
//        sf::Texture backgroundTexture;
//        if (!backgroundTexture.loadFromFile("pictures/MainWind-background.png" /*"C:\\Users\\User\\Desktop\\University\\2 курс 2 семестр\\Курсова робота\\Картинки\\2151127995 (3).jpg"*/)) {
//            return EXIT_FAILURE;
//        }
//        sf::Sprite backgroundSprite(backgroundTexture);
//
//        // Создание кнопок
//        sf::RectangleShape closeButton = createButton(400, 100, 200, 50, sf::Color::White, "Вийти");
//        sf::RectangleShape gameButton = createButton(500, 200, 200, 50, sf::Color::White, "Почати гру");
//
//        // Создание текста для кнопок
//        sf::Font font;
//        font.loadFromFile("arial.ttf"); // Путь к шрифту
//
//        sf::Text closeText("Вийти", font, 30);
//        closeText.setPosition(165, 110);
//        closeText.setFillColor(sf::Color::Black);
//
//        sf::Text gameText("Почати гру", font, 30);
//        gameText.setPosition(105, 210);
//        gameText.setFillColor(sf::Color::Black);
//
//        while (mainWindow.isOpen()) {
//            sf::Event event;
//            while (mainWindow.pollEvent(event)) {
//                if (event.type == sf::Event::Closed) {
//                    mainWindow.close();
//                    return EXIT_SUCCESS; // Signal to end the program
//                }
//                // Обработка нажатия кнопок
//                if (event.type == sf::Event::MouseButtonPressed) {
//                    sf::Vector2i mousePos = sf::Mouse::getPosition(mainWindow);
//                    if (closeButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                        mainWindow.close(); // Закрываем окно при нажатии на кнопку "Close"
//                        return EXIT_SUCCESS; // Signal to end the program
//                    }
//
//                    if (gameButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                        mainWindow.close();
//                        return 1; // Signal to open Game Window
//                    }
//                }
//            }
//
//            mainWindow.clear();
//
//            // Отображаем фон с учетом размера окна
//            backgroundSprite.setScale(mainWindow.getSize().x / backgroundSprite.getLocalBounds().width,
//                mainWindow.getSize().y / backgroundSprite.getLocalBounds().height);
//            mainWindow.draw(backgroundSprite);
//
//            mainWindow.draw(closeButton);
//            mainWindow.draw(gameButton);
//            mainWindow.draw(closeText);
//            mainWindow.draw(gameText);
//            mainWindow.display();
//        }
//
//        return EXIT_SUCCESS;
//    }
//
//    static RectangleShape createButton(float x, float y, float width, float height, sf::Color color, const std::string& buttonText, sf::Texture* buttonTexture = nullptr) {
//        sf::RectangleShape button(sf::Vector2f(width, height));
//        button.setPosition(x, y);
//        button.setFillColor(color);
//        if (buttonTexture) {
//            button.setTexture(buttonTexture);
//        }
//
//        // Создаем текст для кнопки
//        sf::Font font;
//        font.loadFromFile("arial.ttf"); // Путь к шрифту
//
//        sf::Text text(buttonText, font, 20);
//        text.setFillColor(sf::Color::White);
//        text.setPosition(x + (width - text.getLocalBounds().width) / 2, y + (height - text.getLocalBounds().height) / 2);
//
//        return button;
//    }
//}; 



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

public:
    MainWindow() : mainWind(sf::VideoMode(1900, 1050), "MAIN MENU"), closeButton(400, 100, 200, 50, "Вийти", font), gameButton(500, 200, 200, 50, "Почати гру", font) {
       
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

        font.loadFromFile("arial.ttf"); // Load font

        closeButton = Button(400, 100, 200, 50, "Вийти", font);
        gameButton = Button(500, 200, 200, 50, "Почати гру", font);
    }

    void closeWindow() {
        mainWind.close();
    }

    int run() {

        if (!mainWind.isOpen())
            mainWind.create(sf::VideoMode(1900, 1050), "MAIN MENU");

        while (mainWind.isOpen()) {

            Event event;
            
            while (mainWind.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    mainWind.close();
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (closeButton.isClicked(mainWind)) {
                        closeWindow();
                        return EXIT_SUCCESS; //TODO
                    }
                    if (gameButton.isClicked(mainWind)) {
                        closeWindow();
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

        return EXIT_SUCCESS; //TODO
    }
};

