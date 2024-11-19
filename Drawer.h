#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Drawer
{
public:
	void Setup();
	void Draw(sf::RenderWindow& MainWindow);
private:
	sf::Texture arrowUpText;
	sf::Texture arrowDownText;
	sf::Texture arrowLeftText;
	sf::Texture arrowRightText;

	sf::Sprite arrowUp;
	sf::Sprite arrowDown;
	sf::Sprite arrowLeft;
	sf::Sprite arrowRight;
};
