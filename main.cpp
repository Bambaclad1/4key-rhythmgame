#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Drawer.h"
/*
				NEXT SPRINT - Keep pulling the GIT for changes!
				Commit 21-11 | 2 - Target: 25-11
			
	* Buttons work!
	* Add arrows falling down with a constant speed!
	* when they collide, do something! Maybe kill them!
	* use the colored arrows for that!
	* Good luck!

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