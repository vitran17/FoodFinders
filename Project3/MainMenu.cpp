#include "MainMenu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("Academy engraved.ttf"))
    {
        // handle error
    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("1. Search restaurants by zip code delivered by unordered map");
    menu[0].setCharacterSize(40);
    menu[0].setPosition(sf::Vector2f(width / 2 -510, height / (MAX_NUMBER_OF_ITEMS + 1)*3.5));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("2. Search restaurants by zip code delivered by map");
    menu[1].setCharacterSize(40);
    menu[1].setPosition(sf::Vector2f(width / 2 -510, height / (MAX_NUMBER_OF_ITEMS + 1)*4));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("3. Search restaurants by city and cuisine delivered by unordered map");
    menu[2].setCharacterSize(40);
    menu[2].setPosition(sf::Vector2f(width / 2 -510, height / (MAX_NUMBER_OF_ITEMS + 1) * 4.5));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("4. Search restaurants by city and cuisine delivered map");
    menu[3].setCharacterSize(40);
    menu[3].setPosition(sf::Vector2f(width / 2 -510, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("5. Search restaurant by name by unordered map");
    menu[4].setCharacterSize(40);
    menu[4].setPosition(sf::Vector2f(width / 2 -510, height / (MAX_NUMBER_OF_ITEMS + 1) * 5.5));

    menu[5].setFont(font);
    menu[5].setColor(sf::Color::White);
    menu[5].setString("6. Search restaurant by name by map");
    menu[5].setCharacterSize(40);
    menu[5].setPosition(sf::Vector2f(width / 2 -510, height / (MAX_NUMBER_OF_ITEMS + 1) * 6));

    menu[6].setFont(font);
    menu[6].setColor(sf::Color::White);
    menu[6].setString("7. Exit the program");
    menu[6].setCharacterSize(40);
    menu[6].setPosition(sf::Vector2f(width / 2 -510, height / (MAX_NUMBER_OF_ITEMS + 1) * 6.5));


    mainMenuSelected = -1;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (mainMenuSelected - 1 >= 0)
    {
        menu[mainMenuSelected].setColor(sf::Color::White);
        mainMenuSelected--;
        if(mainMenuSelected == -1){
            mainMenuSelected = 6;
        }
        menu[mainMenuSelected].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (mainMenuSelected + 1 <= MAX_NUMBER_OF_ITEMS)
    {
        menu[mainMenuSelected].setColor(sf::Color::White);
        mainMenuSelected++;
        if(mainMenuSelected == 7){
            mainMenuSelected = 0;
        }
        menu[mainMenuSelected].setColor(sf::Color::Red);
    }
}