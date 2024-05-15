#pragma once
#pragma once
#include <SFML/Graphics.hpp>

int Start_Game() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Page Movement", sf::Style::Fullscreen);

    // �������� �����������
    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\User\\Desktop\\�������1.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // ��������� ��������� �������
    sf::Vector2f position(400.f, 300.f);
    sprite.setPosition(position);

    // �������� ���� ���������
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // ��������� ������� ������
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            position.y -= 0.1f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            position.y += 0.1f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            position.x -= 0.1f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            position.x += 0.1f;
        }

        // ���������� ������� �������
        sprite.setPosition(position);

        // ������� ������ � ��������� �������
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}
