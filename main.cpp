#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Drawer.h"

int main()
{
	Game game;
	Drawer drawer;
	sf::RenderWindow MainWindow(sf::VideoMode(1600, 900), "4key rhythm game - DEBUG ver?");

	drawer.SetupTextures();
	drawer.SetupText();
	while (MainWindow.isOpen())
	{
		sf::Event event;
		while (MainWindow.pollEvent(event))
		{
			game.Management(MainWindow, event);
			game.KeyboardHandler(MainWindow, event);
		}
			
		MainWindow.clear(sf::Color::White);
		drawer.Draw(MainWindow);
		MainWindow.display();		

	}
	return 0;
}