#include "gameManagement.h"

gameManagement::gameManagement(sf::RenderWindow& window) : window(window) {}

void gameManagement::PauseGame()
{
	std::cout << "DEBUG| Game Paused! Add some code functonality here to pause the game!" << std::endl;
	window.setFramerateLimit(15);
}

void gameManagement::ContinueGame()
{
	std::cout << "DEBUG| Game has been continued! Add some code functionality to continue the game!" << std::endl;
	window.setFramerateLimit(60);
}