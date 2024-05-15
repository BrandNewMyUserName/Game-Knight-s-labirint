#pragma once
#pragma once
#include <SFML/Graphics.hpp>

int Start_Game() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Page Movement", sf::Style::Fullscreen);

    // Загрузка изображения
    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\User\\Desktop\\Рисунок1.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Установка начальной позиции
    sf::Vector2f position(400.f, 300.f);
    sprite.setPosition(position);

    // Основной цикл программы
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Обработка нажатий клавиш
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

        // Обновление позиции спрайта
        sprite.setPosition(position);

        // Очистка экрана и отрисовка спрайта
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}
