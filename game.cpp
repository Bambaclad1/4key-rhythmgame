#include "game.h"

void Game::Management(sf::Window& window, sf::Event& event)
{
	if (event.type == sf::Event::Closed)
		window.close();
}
