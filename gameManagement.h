#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class gameManagement
{
public:
	gameManagement(sf::RenderWindow& window);

	void PauseGame();
	void ContinueGame();

private:
	sf::RenderWindow& window; 
};

