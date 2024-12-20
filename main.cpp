#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Arrow.h"
#include "Drawer.h"
/*
				NEXT SPRINT - Keep pulling the GIT for changes!
				Commit null |  Target: null

				holiday break update
*/
int main()
{
	std::cout << "Goodluck :)" << std::endl;

	Drawer drawer;
	Game game(drawer);
	sf::Clock clock;
	sf::RenderWindow MainWindow(sf::VideoMode(1600, 900), "4key rhythm game - Main Branch");

	drawer.SetupTextures();
	drawer.SetupText();


	while (MainWindow.isOpen())
	{
		sf::Event event;
		MainWindow.setKeyRepeatEnabled(false);
		while (MainWindow.pollEvent(event))
		{
			game.Management(MainWindow, event);
			game.KeyboardHandler(MainWindow, event);
		}

		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		drawer.Update(deltaTime);

		MainWindow.clear(sf::Color(137, 137, 137));

		drawer.Draw(MainWindow, deltaTime);

		drawer.BoundingBox(MainWindow);

		MainWindow.display();
	}
	return 0;
}