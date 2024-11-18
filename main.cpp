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
			//checkt alle poll events in een aparte class
			game.Management(window, event);
		}
	}
	return 0;
}