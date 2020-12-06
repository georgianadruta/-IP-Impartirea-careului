#ifndef BUTTON_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <cstring>
#include <windows.h>
#define BUTTON_H_INCLUDED

struct Button{
    float xPos, yPos;
    sf::IntRect box;
    sf::Sprite sprite;
    sf::Texture texture;

};

//Button prototype with hover
//It is working but still needs some attention!
class Button1{
    float xPos, yPos;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Color oldColor;

public:
    Button1(std::string filename, float xPos, float yPos);
    bool isHovering(sf::RenderWindow &target);
    void drawButton1(sf::RenderWindow &target);
    void update(sf::RenderWindow &target);

    sf::Sprite getSprite();
};

void setButton(Button &button, std::string filename, sf::IntRect rect, float xPos, float yPos);
void drawButton(Button &button, sf::RenderWindow &window);
void addHover(Button &button, sf::RenderWindow &window);
#endif // BUTTON_H_INCLUDED
