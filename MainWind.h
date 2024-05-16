#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class MainWindow {
public:
    static int CreateMainWindow() {
        // �������� ���� ��� ������� ��������
        sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SFML Page Movement" /*, Style::Fullscreen*/);

        // �������� ����
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("pictures/MainWind-background.png" /*"C:\\Users\\User\\Desktop\\University\\2 ���� 2 �������\\������� ������\\��������\\2151127995 (3).jpg"*/)) {
            return EXIT_FAILURE;
        }
        sf::Sprite backgroundSprite(backgroundTexture);

        // �������� ������
        sf::RectangleShape closeButton = createButton(400, 100, 200, 50, sf::Color::White, "�����");
        sf::RectangleShape gameButton = createButton(500, 200, 200, 50, sf::Color::White, "������ ���");

        // �������� ������ ��� ������
        sf::Font font;
        font.loadFromFile("arial.ttf"); // ���� � ������

        sf::Text closeText("�����", font, 30);
        closeText.setPosition(165, 110);
        closeText.setFillColor(sf::Color::Black);

        sf::Text gameText("������ ���", font, 30);
        gameText.setPosition(105, 210);
        gameText.setFillColor(sf::Color::Black);

        while (mainWindow.isOpen()) {
            sf::Event event;
            while (mainWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    mainWindow.close();
                    return EXIT_SUCCESS; // Signal to end the program
                }
                // ��������� ������� ������
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(mainWindow);
                    if (closeButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        mainWindow.close(); // ��������� ���� ��� ������� �� ������ "Close"
                        return EXIT_SUCCESS; // Signal to end the program
                    }

                    if (gameButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        mainWindow.close();
                        return 1; // Signal to open Game Window
                    }
                }
            }

            mainWindow.clear();

            // ���������� ��� � ������ ������� ����
            backgroundSprite.setScale(mainWindow.getSize().x / backgroundSprite.getLocalBounds().width,
                mainWindow.getSize().y / backgroundSprite.getLocalBounds().height);
            mainWindow.draw(backgroundSprite);

            mainWindow.draw(closeButton);
            mainWindow.draw(gameButton);
            mainWindow.draw(closeText);
            mainWindow.draw(gameText);
            mainWindow.display();
        }

        return EXIT_SUCCESS;
    }

    static RectangleShape createButton(float x, float y, float width, float height, sf::Color color, const std::string& buttonText, sf::Texture* buttonTexture = nullptr) {
        sf::RectangleShape button(sf::Vector2f(width, height));
        button.setPosition(x, y);
        button.setFillColor(color);
        if (buttonTexture) {
            button.setTexture(buttonTexture);
        }

        // ������� ����� ��� ������
        sf::Font font;
        font.loadFromFile("arial.ttf"); // ���� � ������

        sf::Text text(buttonText, font, 20);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + (width - text.getLocalBounds().width) / 2, y + (height - text.getLocalBounds().height) / 2);

        return button;
    }
};