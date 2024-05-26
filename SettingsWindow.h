//#pragma once
//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <string>
//
//class SettingsWindow
//{
//public:
//    SettingsWindow(sf::RenderWindow& window, float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name);
//    void setInitText(sf::Text& text, const sf::String& str, float xpos, float ypos) const;
//    void AlignMenu(int posx);
//    void MoveUp();
//    void MoveDown();
//    void draw();
//    void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);
//    void handleMouseClick(float mouseX, float mouseY);
//    int getSelectedIndex() const;
//    std::string getSelectedMode() const;
//    std::string getSelectedAlgorithm() const;
//    std::string getSelectedMap() const;
//    int run();
//
//private:
//    sf::Font font;
//    sf::Color menu_text_color;
//    sf::Color chose_text_color;
//    sf::Color border_color;
//    float menu_X, menu_Y;
//    int menu_Step, max_menu, size_font;
//    std::vector<sf::Text> mainMenu;
//    int mainMenuSelected;
//    sf::RenderWindow& mywindow;
//
//    // Mode and algorithm options
//    std::vector<std::string> modes = { "Manual", "Auto" };
//    std::vector<std::string> algorithms = { "BFS", "A*" };
//    std::vector<std::string> maps = { "Map 1 (10x10)", "Map 2 (20x20)", "Map 3 (30x30)" };
//    int modeSelected = 0;
//    int algorithmSelected = 0;
//    int mapSelected = 0;
//};
