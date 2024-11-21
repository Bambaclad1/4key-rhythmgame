#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Drawer
{
public:
	void SetupTextures();
	void SetupText();
	void Draw(sf::RenderWindow& MainWindow);
	void BoundingBox(sf::RenderWindow& MainWindow);

	void ChangeTexture(int lane);
	void ResetTexture(int lane);
private:
	sf::Texture arrowUpText;
	sf::Texture arrowDownText;
	sf::Texture arrowLeftText;
	sf::Texture arrowRightText;

	sf::Texture arrowUpKDText;
	sf::Texture arrowDownKDText;
	sf::Texture arrowLeftKDText;
	sf::Texture arrowRightKDText;

	sf::Sprite arrowUp;
	sf::Sprite arrowDown;
	sf::Sprite arrowLeft;
	sf::Sprite arrowRight;

	sf::Font nerdfont;
	sf::Text text;


	
};
