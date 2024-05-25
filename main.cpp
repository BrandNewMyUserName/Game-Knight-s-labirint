#include <SFML/Graphics.hpp>
#include <iostream>
#include "SettingsWindow.h"
#include "GameSettings.h"
#include "MainWindow.h"
#include "GameWind.h"
#include <vector>
#include <windows.h>

using namespace std;
using namespace sf;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    GameSettings &Settings = GameSettings::getInstance();

    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Головне Меню");
    std::vector<sf::String> menuItems = { L"Почати гру", L"Налаштування", L"Вийти" };
    sf::String Title = L"Лабіринт лицаря: Пошук скарбів";

    MainWindow mainWind(window, 1100.0f, 200.0f, 60, 100, menuItems, Title);
    mainWind.AlignMenu(3);



    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("pictures/MainWind-background.png")) {
        std::cerr << "Error loading background texture\n";
        return -1;
    }


    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    backgroundSprite.setScale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainWind.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    mainWind.MoveDown();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mainWind.handleMouseClick(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                    int selected = mainWind.getSelectedIndex();
                    if (selected == 0) {
                        window.close();
                        GameWind game;
                        game.run();
                    }
                    if (selected == 1) {
                        //std::vector<sf::String> settingsItems = { L"Режим гри", L"Мапа", L"Алгоритм" };
                        //SettingsWindow settings(window, 100.0f, 200.0f, 48, 100, settingsItems);
                        //settings.run();
                    }
                    if (selected == 2) {
                        window.close();
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        mainWind.draw();
        window.display();
    }

    return 0;
}
