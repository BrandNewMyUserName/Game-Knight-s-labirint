
#include <SFML/Graphics.hpp>
#include "MainWind.h"
#include "GameWind.h" 

int main() {



    MainWindow mainWindow;

    
    while (mainWindow.run()) {
        GameWind GameWindow;
        GameWindow.run();

    }



    return 0;
}



//#include <SFML/Graphics.hpp>
//
////#define OPEN_GAMEWIND 1
////#define EXIT_PROGRAM 0
//
//// ������� ��� �������� ������
//sf::RectangleShape createButton(float x, float y, float width, float height, sf::Color color) {
//    sf::RectangleShape button(sf::Vector2f(width, height));
//    button.setPosition(x, y);
//    button.setFillColor(color);
//    return button;
//}
//
//int main() {
//    // �������� ���� ��� ������� ��������
//    sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SFML Page Movement");// , sf::Style::Fullscreen);
//
//    // �������� ����
//    sf::Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("pictures/MainWind-background.jpg")) {
//        return EXIT_FAILURE;
//    }
//    sf::Sprite backgroundSprite(backgroundTexture);
//
//    // �������� ������
//    sf::RectangleShape closeButton = createButton(100, 100, 200, 50, sf::Color::Red);
//    sf::RectangleShape gameButton = createButton(100, 200, 200, 50, sf::Color::Green);
//
//    // �������� ������ ��� ������
//    sf::Font font;
//    font.loadFromFile("arial.ttf"); // ���� � ������
//
//    sf::Text closeText("Close", font, 30);
//    closeText.setPosition(165, 110);
//    closeText.setFillColor(sf::Color::White);
//
//    sf::Text gameText("Game Window", font, 30);
//    gameText.setPosition(105, 210);
//    gameText.setFillColor(sf::Color::White);
//
//    while (mainWindow.isOpen()) {
//        sf::Event event;
//        while (mainWindow.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                mainWindow.close();
//            }
//            // ��������� ������� ������
//            if (event.type == sf::Event::MouseButtonPressed) {
//                sf::Vector2i mousePos = sf::Mouse::getPosition(mainWindow);
//                if (closeButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                    mainWindow.close(); // ��������� ���� ��� ������� �� ������ "Close"
//                    //return EXIT_FAILURE;
//                }
//
//                if (gameButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                    // ��������� ����� ���� ��� ������� �� ������ "Game Window"
//                    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "Game Window");
//                    while (gameWindow.isOpen()) {
//                        sf::Event gameEvent;
//                        while (gameWindow.pollEvent(gameEvent)) {
//                            if (gameEvent.type == sf::Event::Closed) {
//                                gameWindow.close();
//                                //return OPEN_GAMEWIND;
//                            }
//                        }
//                        gameWindow.clear();
//                        gameWindow.display();
//                    }
//                }
//            }
//        }
//
//        mainWindow.clear();
//        mainWindow.draw(backgroundSprite); // ���������� ���
//        mainWindow.draw(closeButton);
//        mainWindow.draw(gameButton);
//        mainWindow.draw(closeText);
//        mainWindow.draw(gameText);
//        mainWindow.display();
//    }
//    return EXIT_SUCCESS;
//}


