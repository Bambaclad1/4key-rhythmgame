#include "game.h"

Game::Game()
{
	KeyLane1 = sf::Keyboard::D;
	KeyLane2 = sf::Keyboard::F;
	KeyLane3 = sf::Keyboard::J;
	KeyLane4 = sf::Keyboard::K;
}

void Game::Management(sf::Window& window, sf::Event& event)
{
	// Part of the poll event loop in main
	if (event.type == sf::Event::Closed)
		window.close();

	if (event.type == sf::Event::KeyPressed)
		std::cout << "TEMP | Ik heb een knop geklikt!\n";

	if (event.type == sf::Event::Resized)
		std::cout << "Resized, Width: " << event.size.width << " Height: " << event.size.height << "\n";

	if (event.type == sf::Event::LostFocus)
		std::cout << "window Lost focus.\n";

	if (event.type == sf::Event::GainedFocus)
		std::cout << "window Gained focus.\n";
}
void Game::KeyboardHandler(sf::Window& window, sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == KeyLane1)
		{
			std::cout << "Pressed KeyLane1";
		}
		else if (event.key.code == KeyLane2)
		{
			std::cout << "Pressed KeyLane2";
		}
		else if (event.key.code == KeyLane3)
		{
			std::cout << "Pressed KeyLane3";
		}
		else if (event.key.code == KeyLane4)
		{
			std::cout << "Pressed KeyLane4";
		}
		
	}
}
;