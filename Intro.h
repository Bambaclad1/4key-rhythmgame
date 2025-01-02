#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Intro
{
public:
	Intro();
	void Update(sf::RenderWindow& window);

	void loadTextures();

	bool canbreak = false;
private:
	sf::Texture screen1;

	sf::Sprite screenSprite;

	sf::Clock introClock;

};

