#pragma once
#include <SFML/Window.hpp>
#include <iostream>

class Game
{
public:
	Game();
	void Management(sf::Window& window, sf::Event& event);
	void KeyboardHandler(sf::Window& window, sf::Event& event);
private:
    sf::Keyboard::Key KeyLane1;
    sf::Keyboard::Key KeyLane2;
    sf::Keyboard::Key KeyLane3;
    sf::Keyboard::Key KeyLane4;
};

