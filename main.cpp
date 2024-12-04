#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Drawer.h"
/*
				NEXT SPRINT - Keep pulling the GIT for changes!
				Commit 3-12-2024 | 2 - Target: 5-12-2024
				Oh boy, this is going to be a long sprint.

		* We now have a idea of how everything is going to work. Epic.
		* Get a class working
		* Arrow class
		* Give it attributes such as position and stuff
		* Make it move down and stuff
		* Make a class for every map
		* That, just get easy map eidigtng and make the
		* arroww work w it
*/
/*                 Cheatsheet!

			sf::Sprite arrow1;	//up
			sf::Sprite arrow2;	//down
			sf::Sprite arrow3;	//left
			sf::Sprite arrow4;	//right

			Rev2
			sf::Sprite arrow1;	// Left
			sf::Sprite arrow2;	// Up
			sf::Sprite arrow3;	// Down
			sf::Sprite arrow4;	// Right
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

		MainWindow.clear(sf::Color(137, 137, 137));

		drawer.Draw(MainWindow); // base arrows check for input

		drawer.BoundingBox(MainWindow);

		MainWindow.display();
	}
	return 0;
}