#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Drawer.h"
/*
				NEXT SPRINT - Keep pulling the GIT for changes!
			
	* Keylanes react to bounding box, giving a visualization.
	* Also giving a sense that the button IS infact pressed and does something
	* For example, the arrow will give a feedback, that it for example lightens up or bounces!
	* WOW!

*/
int main()
{
	Drawer drawer;
	Game game(drawer);
	sf::RenderWindow MainWindow(sf::VideoMode(1600, 900), "4key rhythm game - DEBUG ver?");

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
			
		MainWindow.clear(sf::Color(137,137,137));

		drawer.Draw(MainWindow);
		drawer.BoundingBox(MainWindow);

		MainWindow.display();		

	}
	return 0;
}