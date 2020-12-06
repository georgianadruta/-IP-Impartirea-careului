#ifndef CHECKSOLUTION_H_INCLUDED
#define CHECKSOLUTION_H_INCLUDED

#include <string.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "square.h"
#include "solution.h"
#include "Button.h"
#include <SFML/Audio.hpp>



void giveSolution();

bool checkSolution();

void showWinOrLose(sf::RenderWindow &window, std::string secunde);



#endif // CHECKSOLUTION_H_INCLUDED
