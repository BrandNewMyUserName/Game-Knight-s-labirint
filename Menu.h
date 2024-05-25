#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
	float menu_X;                                     //                    X
	float menu_Y;				                      //                    Y
	int menu_Step;                                    //                               
	int max_menu;                                     //                                     
	int size_font;                                    //              
	int mainMenuSelected;                             //                            
	sf::Font font;                                    //            
	std::vector<sf::Text> mainMenu;                   //                                  

	sf::Color menu_text_color = sf::Color::White;      //          
	sf::Color chose_text_color = sf::Color::Yellow;    //                 
	sf::Color border_color = sf::Color::Black;         //                    

	//                      
	void setInitText(sf::Text& text, const sf::String& str, float xpos, float ypos) const;

	sf::RenderWindow& mywindow;                       //                           
public:

	Menu(sf::RenderWindow& window, float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name, sf::String nameTitle);

	void draw();                                     //            

	void MoveUp();                                   //                              

	void MoveDown();                                 //                             

	//                             
	void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);

	void AlignMenu(int posx);       //                             (                              )

	void handleMouseClick(float mouseX, float mouseY);

	int getSelectedIndex();//                                    


};