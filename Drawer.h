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
	void Update(float deltaTime);
	void BoundingBox(sf::RenderWindow& MainWindow);

	void ChangeTexture(int lane);
	void ResetTexture(int lane);
private:
	sf::Texture arrowUpText; // Normal Arrows, bar arrows.
	sf::Texture arrowDownText;
	sf::Texture arrowLeftText;
	sf::Texture arrowRightText;
	
	sf::Texture arrowUpKDText; // Pressed down arrows.
	sf::Texture arrowDownKDText;
	sf::Texture arrowLeftKDText;
	sf::Texture arrowRightKDText;

	sf::Texture arrowUpFText; // Falling down arrows (instantiate them.)
	sf::Texture arrowDownFText;
	sf::Texture arrowLeftFText;
	sf::Texture arrowRightFText;

	sf::Sprite arrowUp;
	sf::Sprite arrowDown;
	sf::Sprite arrowLeft;
	sf::Sprite arrowRight;

	sf::Sprite arrow1;
	sf::Sprite arrow2;
	sf::Sprite arrow3;
	sf::Sprite arrow4;

	sf::Font nerdfont;
	sf::Text text;


	
};
