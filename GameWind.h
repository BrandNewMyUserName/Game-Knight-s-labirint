#pragma once

using namespace sf;

int OpenGameWindow() {
    sf::RenderWindow gameWindow(sf::VideoMode(1920, 1080), "SFML Page Movement" /*,sf::Style::Fullscreen*/);

    Image knight;
    if (!knight.loadFromFile("C:\\Users\\User\\Desktop\\Рисунок1.png")) {
        return EXIT_FAILURE;
    }
    ;

    // Загрузка изображения
    Texture knightTexture;
    knightTexture.loadFromImage(knight);

    Sprite knighSprite;
    knighSprite.setTexture(knightTexture);
    //knighSprite.setTextureRect(IntRect());

    // Установка начальной позиции
    sf::Vector2f position(400.f, 300.f);
    knighSprite.setPosition(position);

    // Основной цикл программы
    while (gameWindow.isOpen()) {
        sf::Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            gameWindow.close();
            return EXIT_FAILURE;
        }

        // Обновление позиции спрайта
        knighSprite.setPosition(position);

        // Очистка экрана и отрисовка спрайта
        gameWindow.clear();
        gameWindow.draw(knighSprite);
        gameWindow.display();
    }

    return EXIT_SUCCESS;
}