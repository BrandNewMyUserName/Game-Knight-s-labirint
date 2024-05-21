
#include <SFML/Graphics.hpp>
#include <iostream>
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

