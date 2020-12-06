#include "Button.h"

void setButton(Button &button, std::string filename, sf::IntRect rect, float xPos, float yPos){
    button.box=rect;
    button.texture.loadFromFile(filename);
    button.sprite.setTexture(button.texture);
    button.sprite.setPosition(xPos, yPos);
    button.sprite.setColor(sf::Color(255, 255, 255, 200));

}

void drawButton(Button &button, sf::RenderWindow &window){
    window.draw(button.sprite);
}

void addHover(Button &button, sf::RenderWindow &window){
    sf::Color oldColor = button.sprite.getColor();
    button.sprite.setColor(sf::Color(255, 255, 255, 128));
    window.draw(button.sprite);
    Sleep(1000);
    button.sprite.setColor(oldColor);
    //window.draw(button.sprite);
}


Button1::Button1(std::string filename, float xPos, float yPos){
    this->xPos=xPos;
    this->yPos=yPos;

    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(xPos, yPos);
    oldColor = sprite.getColor();
}

bool Button1::isHovering(sf::RenderWindow &target){
    float Mx = sf::Mouse::getPosition(target).x;
    float My = sf::Mouse::getPosition(target).y;

    if(sprite.getGlobalBounds().contains(Mx, My))
        return true;
    else
        return false;
}

void Button1::drawButton1(sf::RenderWindow &target){
    update(target);
    target.draw(sprite);
}


void Button1::update(sf::RenderWindow &target){
    if(isHovering(target))
        sprite.setColor(sf::Color(255, 255, 255, 200));
        else
            sprite.setColor(oldColor);
}

sf::Sprite Button1::getSprite(){
    return this->sprite;
}
