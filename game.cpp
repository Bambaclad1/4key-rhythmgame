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
	// poll event loop in de main
	if (event.type == sf::Event::Closed)
		window.close();

	if (event.type == sf::Event::Resized)
		std::cout << "Resized, Width: " << event.size.width << " Height: " << event.size.height << "\n";

	if (event.type == sf::Event::LostFocus)
		std::cout << "window Lost focus.\n";

	if (event.type == sf::Event::GainedFocus)
		std::cout << "window Gained focus.\n";
}
void Game::KeyboardHandler(sf::Window& window, sf::Event& event)
{
	window.setKeyRepeatEnabled(false);

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == KeyLane1)
		{
			std::cout << "Pressed KeyLane1\n";
		}
		else if (event.key.code == KeyLane2)
		{
			std::cout << "Pressed KeyLane2\n";
		}
		else if (event.key.code == KeyLane3)
		{
			std::cout << "Pressed KeyLane3\n";
		}
		else if (event.key.code == KeyLane4)
		{
			std::cout << "Pressed KeyLane4\n";
		}
		
	}
}
;