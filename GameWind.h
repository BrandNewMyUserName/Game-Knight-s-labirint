#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include"Map.h"


using namespace sf;
using namespace std;


class Character {
public: float x, y, speed;
      String Picture_name;
      Image characterImage;
      Texture characterTexture;
      Sprite characterSprite;

      Character() {
          this->x = 250;
          this->y = 250;
          Picture_name = "Knight_spikes.png";

          this->characterImage;
          try {
              if (!this->characterImage.loadFromFile("pictures/" + this->Picture_name)) {
                  throw "Unable to find a character image";
              }
          }
          catch (const char* exception)
          {
              cerr << "Error: " << exception << '\n';
          }

          this->characterTexture.loadFromImage(this->characterImage);

          this->characterSprite.setTexture(this->characterTexture);
          this->characterSprite.setTextureRect(IntRect(8, 15, 180, 112));
       
          this->characterSprite.setPosition(this->x, this->y);
      }

      float getX() {
          return x;
      }

      float getY() {
          return y;
      }

};

class GameWindow {
public:
    int width_screen, height_screen;
    String WindowName;
    Character character;

    Map MAP;

    Image mapImage;
    Texture mapTexture;
    Sprite s_map;
    String imageLink;

    RenderWindow gameWind;

    GameWindow() {
        this->width_screen = 1920;
        this->height_screen = 1080;
        this->WindowName = "Knight's Labyrinth: Treasure Hunt";
        imageLink = "map.png";

        try {
            if (!mapImage.loadFromFile("pictures/" + imageLink)) {
                throw "Unable to find an map image";
            }
        }
        catch (const char* exception)
        {
            cerr << "Error: " << exception << '\n';
        }

        mapTexture.loadFromImage(mapImage);
        s_map.setTexture(mapTexture);

        character = Character();

        RenderWindow gameWind(VideoMode(this->width_screen, this->height_screen), this->WindowName /*,sf::Style::Fullscreen*/);
    }

    void draw() {
        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (MAP.Grid[i][j] == '0')  s_map.setTextureRect(IntRect(0, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION)); //если встретили символ пробел, то рисуем 1й квадратик
                if (MAP.Grid[i][j] == '1')  s_map.setTextureRect(IntRect(PICTURE_RESOLUTION, 0, PICTURE_RESOLUTION, PICTURE_RESOLUTION));//если встретили символ s, то рисуем 2й квадратик
                //if ((Map[i][j] == )) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


                s_map.setPosition(j * PICTURE_RESOLUTION, i * PICTURE_RESOLUTION);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                gameWind.draw(s_map);//рисуем квадратики на экран
            }

        }

        gameWind.clear();
        gameWind.draw(character.characterSprite);
        gameWind.display();
    };


    int run() {
        Clock clock;
        
        while (gameWind.isOpen()) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time /= 800;
            float CurrentFrame = 0;
            sf::Event event;

            while (gameWind.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    gameWind.close();
                }
            }

            // ЕМУЛЯЦІЯ РУХУ ЛИЦАРЯ ПІД ЧАС НАТИСКАННЯ КЛАВІШ
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().y % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(600, 25, 75, 74));
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(600, 210, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(600, 400, 75, 74));
                    break;
                }

                character.characterSprite.move(0, -0.1 * time);
                //position.y -= 0.1f * time;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().y % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(66, 210, 75, 74));
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(250, 210, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(435, 210, 75, 74));
                    break;
                }
                character.characterSprite.move(0, 0.1 * time);
                //position.y += 0.1f*time;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().x % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(67, 400, 75, 74));
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(250, 400, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(435, 400, 75, 74));
                    break;
                }
                character.characterSprite.move(-0.1 * time, 0);
                // position.x -= 0.1f*time;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                int xTexture = 0;
                xTexture = (int)character.characterSprite.getPosition().x % 3;
                switch (xTexture) {
                case 0:
                    character.characterSprite.setTextureRect(IntRect(67, 25, 75, 74));
                    break;

                case 1:
                    character.characterSprite.setTextureRect(IntRect(250, 25, 75, 74));
                    break;

                case 2:
                    character.characterSprite.setTextureRect(IntRect(435, 25, 75, 74));
                    break;
                }

                character.characterSprite.move(0.1 * time, 0);
                // position.x += 0.1f* time;
            }

            // ПОКРАЩЕНЕ КЕРУВАННЯ АКТОРОМ

            //if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            //        CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            //        if (CurrentFrame > 3) 
            //            CurrentFrame -= 3; //если пришли к третьему кадру - откидываемся назад.
            //        knightSprite.setTextureRect(IntRect(180 * int(CurrentFrame), 15, 180, 112)); 
            //        //knightSprite.setTextureRect(IntRect(8, 15, 100, 112));
            //        knightSprite.move(0.1 * time, 0);//происходит само движение персонажа вправо
            //}
            

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                gameWind.close();
            }

            void draw();

            
        }
        return EXIT_SUCCESS;

        //int OpenGameWindow() {
        //    sf::RenderWindow gameWindow(sf::VideoMode(1920, 1080), "SFML Page Movement" /*,sf::Style::Fullscreen*/);
        //    class Player {
        //    private: float x, y;
        //    public:
        //        float w, h, dx, dy, speed;
        //        int dir;
        //        String File;
        //        Image image;
        //        Texture texture;
        //        Sprite sprite;
        //        Player(String F, float X, float Y, float W, float H) {
        //            dx = 0; dy = 0; speed = 0; dir = 0;
        //            File = F;
        //            w = W; h = H;
        //            image.loadFromFile("images/" + File);
        //            image.createMaskFromColor(Color(41, 33, 59));
        //            texture.loadFromImage(image);
        //            sprite.setTexture(texture);
        //            x = X; y = Y;
        //            sprite.setTextureRect(IntRect(0, 0, w, h));
        //        }
        //        void update(float time)
        //        {
        //            switch (dir)
        //            {
        //            case 0: dx = speed; dy = 0; break;
        //            case 1: dx = -speed; dy = 0; break;
        //            case 2: dx = 0; dy = speed; break;
        //            case 3: dx = 0; dy = -speed; break;
        //            }
        //            x += dx * time;
        //            y += dy * time;
        //            speed = 0;
        //            sprite.setPosition(x, y);
        //            interactionWithMap();//вызываем функцию, отвечающую за взаимодействие с картой
        //        }
        //        void interactionWithMap()//ф-ция взаимодействия с картой
        //        {
        //            for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по тайликам, контактирующим с игроком,, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
        //                for (int j = x / 32; j < (x + w) / 32; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
        //                {
        //                    if (MAP[i][j] == '0')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
        //                    {
        //                        if (dy > 0)//если мы шли вниз,
        //                        {
        //                            y = i * 32 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
        //                        }
        //                        if (dy < 0)
        //                        {
        //                            y = i * 32 + 32;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
        //                        }
        //                        if (dx > 0)
        //                        {
        //                            x = j * 32 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
        //                        }
        //                        if (dx < 0)
        //                        {
        //                            x = j * 32 + 32;//аналогично идем влево
        //                        }
        //                    }
        //                    if (MAP[i][j] == 's') { //если символ равен 's' (камень)
        //                        x = 300; y = 300;//какое то действие... например телепортация героя
        //                        MAP[i][j] = ' ';//убираем камень, типа взяли бонус. можем и не убирать, кстати.
        //                    }
        //                }
        //        }
        //        float getplayercoordinateX() {
        //            return x;
        //        }
        //        float getplayercoordinateY() {
        //            return y;
        //        }
        //    };
        //    //СТВОРЕННЯ ЛИЦАРЯ
        //    //СТВОРЕННЯ КАРТИ
        //    
        //    // Основной цикл программы
        //}
    }
};

