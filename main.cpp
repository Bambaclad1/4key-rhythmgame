#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Drawer.h"
/*
				NEXT SPRINT - Keep pulling the GIT for changes!
				Commit 3-12-2024 | 2 - Target: 4-12-2024
			
		* Get a class working 
		* Arrow class
		* Give it attributes such as position and stuff
		* Make it move down and stuff
		* Make a class for every map
		* That, just get easy map eidigtng and make the 
		* arroww work w it
;

*/
int main()
{
	Drawer drawer;
	Game game(drawer);
	sf::Clock clock; 
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

		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		drawer.Update(deltaTime);  


		MainWindow.clear(sf::Color(137,137,137));

		drawer.Draw(MainWindow); // base arrows check for input
		drawer.BoundingBox(MainWindow);

		MainWindow.display();		

	}
	return 0;
}