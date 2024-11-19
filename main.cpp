#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Loader.h"

int main()
{
	Game game;
	Loader loader;

	sf::RenderWindow window(sf::VideoMode(800, 600), "4key rhythm game - DEBUG");

	loader.Preload();
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