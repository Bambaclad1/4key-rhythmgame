#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameManagement.h"


int main()
{
	//sf::Style::None
	sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
	window.setPosition(sf::Vector2i(555, 0));
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	gameManagement game(window);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::LostFocus)
				game.PauseGame();

			if (event.type == sf::Event::GainedFocus)
				game.ContinueGame();

			if (event.type == sf::Event::Resized)
			{
				std::cout << "new width: " << event.size.width << std::endl;
				std::cout << "new height: " << event.size.height << std::endl;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}