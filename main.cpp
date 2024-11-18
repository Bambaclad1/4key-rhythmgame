#include <SFML/Window.hpp>
#include <iostream>
#include "game.h"
int main()
{
	Game game;
	sf::Window window(sf::VideoMode(800, 600), "My window");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			game.Management(window, event);
			game.KeyboardHandler(window, event);
		}
			

	
	}
	return 0;
}