//#pragma once
//#include "SettingsWindow.h"
//#include <SFML/Graphics.hpp>
//#include <windows.h>
//#include <iostream>
//
//void SettingsWindow::setInitText(sf::Text& text, const sf::String& str, float xpos, float ypos) const
//{
//    text.setFont(font);
//    text.setFillColor(menu_text_color);
//    text.setString(str);
//    text.setCharacterSize(size_font);
//    text.setPosition(xpos, ypos);
//    text.setOutlineThickness(3);
//    text.setOutlineColor(border_color);
//}
//
//void SettingsWindow::AlignMenu(int posx)
//{
//    float nullx = 0;
//    for (int i = 0; i < max_menu; i++) {
//        switch (posx)
//        {
//        case 0:
//            nullx = 0;
//            break;
//        case 1:
//            nullx = mainMenu[i].getLocalBounds().width;
//            break;
//        case 2:
//            nullx = mainMenu[i].getLocalBounds().width / 2;
//            break;
//        default:break;
//        }
//        mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);
//    }
//}
//
//SettingsWindow::SettingsWindow(sf::RenderWindow& window, float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name)
//    : menu_X(menux), menu_Y(menuy), menu_Step(step), max_menu(static_cast<int>(name.size())), size_font(sizeFont), mainMenu(name.size()), mywindow(window)
//{
//    if (!font.loadFromFile("Fonts/troika.otf")) exit(32);
//
//    for (int i = 0, ypos = static_cast<int>(menu_Y); i < max_menu; i++, ypos += menu_Step)
//        setInitText(mainMenu[i], name[i], menu_X, static_cast<float>(ypos));
//    mainMenuSelected = 0;
//    mainMenu[mainMenuSelected].setFillColor(chose_text_color);
//}
//
//void SettingsWindow::MoveUp()
//{
//    mainMenuSelected--;
//    if (mainMenuSelected >= 0) {
//        mainMenu[mainMenuSelected].setFillColor(chose_text_color);
//        mainMenu[mainMenuSelected + 1].setFillColor(menu_text_color);
//    }
//    else {
//        mainMenu[0].setFillColor(menu_text_color);
//        mainMenuSelected = max_menu - 1;
//        mainMenu[mainMenuSelected].setFillColor(chose_text_color);
//    }
//}
//
//void SettingsWindow::MoveDown()
//{
//    mainMenuSelected++;
//    if (mainMenuSelected < max_menu) {
//        mainMenu[mainMenuSelected - 1].setFillColor(menu_text_color);
//        mainMenu[mainMenuSelected].setFillColor(chose_text_color);
//    }
//    else {
//        mainMenu[max_menu - 1].setFillColor(menu_text_color);
//        mainMenuSelected = 0;
//        mainMenu[mainMenuSelected].setFillColor(chose_text_color);
//    }
//}
//
//void SettingsWindow::draw()
//{
//    for (int i = 0; i < max_menu; i++) mywindow.draw(mainMenu[i]);
//
//    // Display current mode and algorithm selection
//    sf::Text modeText, algorithmText;
//    setInitText(modeText, "Mode: " + modes[modeSelected], 500.0f, 400.0f);
//    setInitText(algorithmText, "Algorithm: " + algorithms[algorithmSelected], 500.0f, 450.0f);
//    mywindow.draw(modeText);
//    if (modeSelected == 1) { // Show algorithm selection only if mode is "Auto"
//        mywindow.draw(algorithmText);
//    }
//}
//
//void SettingsWindow::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
//{
//    menu_text_color = menColor;
//    chose_text_color = ChoColor;
//    border_color = BordColor;
//    for (int i = 0; i < max_menu; i++) {
//        mainMenu[i].setFillColor(menu_text_color);
//        mainMenu[i].setOutlineColor(border_color);
//    }
//    mainMenu[mainMenuSelected].setFillColor(chose_text_color);
//}
//
//void SettingsWindow::handleMouseClick(float mouseX, float mouseY)
//{
//    for (int i = 0; i < max_menu; i++) {
//        sf::FloatRect bounds = mainMenu[i].getGlobalBounds();
//        if (bounds.contains(mouseX, mouseY)) {
//            mainMenu[mainMenuSelected].setFillColor(menu_text_color); // Deselect current
//            mainMenuSelected = i;
//            mainMenu[mainMenuSelected].setFillColor(chose_text_color); // Select new
//            break;
//        }
//    }
//}
//
//int SettingsWindow::getSelectedIndex() const
//{
//    return mainMenuSelected;
//}
//
//std::string SettingsWindow::getSelectedMode() const
//{
//    return modes[modeSelected];
//}
//
//std::string SettingsWindow::getSelectedAlgorithm() const
//{
//    return algorithms[algorithmSelected];
//}
//
//std::string SettingsWindow::getSelectedMap() const
//{
//    return maps[mapSelected];
//}
//
//int run() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//
//
//    // Set colors for the text menu
//    setColorTextMenu(sf::Color::White, sf::Color::Red, sf::Color::Black);
//
//    // Load background
//    sf::Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("pictures/MainWind-background.png")) {
//        std::cerr << "Error loading background texture\n";
//        return -1;
//    }
//
//    sf::Sprite backgroundSprite;
//    backgroundSprite.setTexture(backgroundTexture);
//
//    // Scale background to fit window
//    sf::Vector2u windowSize = window.getSize();
//    sf::Vector2u textureSize = backgroundTexture.getSize();
//    backgroundSprite.setScale(
//        float(windowSize.x) / textureSize.x,
//        float(windowSize.y) / textureSize.y
//    );
//
//
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            // Key pressed
//            if (event.type == sf::Event::KeyPressed)
//            {
//                if (event.key.code == sf::Keyboard::Up)
//                {
//                    mainWind.MoveUp();
//                }
//                if (event.key.code == sf::Keyboard::Down)
//                {
//                    mainWind.MoveDown();
//                }
//            }
//
//            // Mouse button pressed
//            if (event.type == sf::Event::MouseButtonPressed)
//            {
//                if (event.mouseButton.button == sf::Mouse::Left)
//                {
//                    mainWind.handleMouseClick(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
//                    int selected = mainWind.getSelectedIndex();
//                    if (selected == 0) { // "Почати гру"
//                        GameWind game;
//                        game.run();
//                    }
//
//                    if (selected == 1) { // "Налаштування гру"
//                        std::vector<sf::String> settingsItems = { L"Режим гри", L"Мапа", L"Алгоритм" };
//                        SettingsWindow settings(window, 100.0f, 200.0f, 48, 100, settingsItems);
//
//                    }
//
//                    if (selected == 2) { // "Вийти"
//                        window.close();
//                    }
//                }
//            }
//        }
//
//        // Clear screen
//        window.clear();
//
//        // Draw background
//        window.draw(backgroundSprite);
//
//        // Draw the menu
//        mainWind.draw();
//
//        // Update the window
//        window.display();
//    }
//
//    return 0;
//
//}