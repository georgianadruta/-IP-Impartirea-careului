#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "square.h"
#include "Button.h"
#include "checksolution.h"

extern bool help;

enum GameDificulty {
        Easy = 0,
        Medium = 1,
        Hard = 2

};


struct square1{
    sf::RectangleShape rec;
    sf::Color outlineColor = sf::Color::White;
    bool hasPiece;
    int pieceColor;
    int pieceNumber;
    float posx;
    float posy;

};

extern square1 square[8][8];

void initSquare1(square1& square, float posx, float posy, bool piece, int pieceNumber);
void updateSquareColor(square1& csquare, sf::Color color);
sf::Color getcolor(square1& csquare);

bool isSquareAvailable(square1 square);

void checkSquare(square1& square, sf::Color color, int o, int p);

void initTable();

void drawTable(sf::RenderWindow& target);

void runGame(sf::RenderWindow & window, GameDificulty dificulty);


#endif
