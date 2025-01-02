#include "intro.h"

Intro::Intro()
{
	loadTextures();
	introClock.restart();
	screenSprite.setScale(0.9f, 0.9f);
	screenSprite.setTexture(screen1);
	std::cout << "Intro Loaded!" << std::endl;
}

void Intro::loadTextures()
{
	if (!screen1.loadFromFile("resources/layers/im just like a onion.png"))
	{
		std::cout << "Error! Unable to load intro.h files! Check resources/layers if the files are there!" << std::endl;
	}
}

void Intro::Update(sf::RenderWindow& window)
{
	sf::Time elapsed1 = introClock.getElapsedTime();

	window.draw(screenSprite);

	if (elapsed1.asSeconds() > 0.0f)
		canbreak = true;
}