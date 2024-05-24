#include <SFML/Graphics.hpp>
#include <iostream>
#include "SettingsWindow.h"
#include "MainWindow.h"
#include "GameWind.h"
#include <vector>
#include <windows.h>

using namespace std;
using namespace sf;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Лабіринт");

    // Menu items
    std::vector<sf::String> menuItems = { L"Почати гру", L"Налаштування", L"Вийти" };


    // Create SettingsWindow object
    MainWindow mainWind(window, 1100.0f, 200.0f, 60, 100, menuItems); // Increased font size and step
    mainWind.AlignMenu(3);


    // Set colors for the text menu
    mainWind.setColorTextMenu(sf::Color::White, sf::Color::Red, sf::Color::Black);

    // Load background
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("pictures/MainWind-background.png")) {
        std::cerr << "Error loading background texture\n";
        return -1;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Scale background to fit window
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    backgroundSprite.setScale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );

    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Key pressed
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    mainWind.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    mainWind.MoveDown();
                }
            }

            // Mouse button pressed
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mainWind.handleMouseClick(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                    int selected = mainWind.getSelectedIndex();
                    if (selected == 0) { // "Почати гру"
                        GameWind game;
                        game.run();
                    }

                    if (selected == 1) { // "Налаштування гру"
                        std::vector<sf::String> settingsItems = { L"Режим гри", L"Мапа", L"Алгоритм" };
                        SettingsWindow settings(window, 100.0f, 200.0f, 48, 100, settingsItems);

                    }

                    if (selected == 2) { // "Вийти"
                        window.close();
                    }
                }
            }
        }

        // Clear screen
        window.clear();

        // Draw background
        window.draw(backgroundSprite);

        // Draw the menu
        mainWind.draw();

        // Update the window
        window.display();
    }

    return 0;
}
