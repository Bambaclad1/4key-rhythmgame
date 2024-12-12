#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class ControllerLeft
{
public:
	ControllerLeft();
	~ControllerLeft();
private:
	sf::Texture arrowControllerTextureLeft;
	sf::Sprite arrowControllerLeft;
};

