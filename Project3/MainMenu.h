#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 8

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {
        return mainMenuSelected;
    }

private:
    int mainMenuSelected;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
