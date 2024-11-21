#include "Game.h"

Game::Game(Drawer& aDrawer)
{
    drawer = &aDrawer;
	KeyLane1 = sf::Keyboard::D;
	KeyLane2 = sf::Keyboard::F;
	KeyLane3 = sf::Keyboard::J;
	KeyLane4 = sf::Keyboard::K;
}



void Game::Management(sf::RenderWindow& MainWindow, sf::Event& event)
{
	// poll event loop in de main
	if (event.type == sf::Event::Closed)
		MainWindow.close();

	if (event.type == sf::Event::Resized)
		std::cout << "Resized, Width: " << event.size.width << " Height: " << event.size.height << "\n";

	if (event.type == sf::Event::LostFocus)
		std::cout << "window Lost focus.\n";

	if (event.type == sf::Event::GainedFocus)
		std::cout << "window Gained focus.\n";
}


void Game::KeyboardHandler(sf::RenderWindow& MainWindow, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == KeyLane1)
        {
            drawer->ChangeTexture(1);
            std::cout << "KeyLane 1 pressed" << std::endl;
        }
        else if (event.key.code == KeyLane2)
        {
            drawer->ChangeTexture(2);
            std::cout << "KeyLane 2 pressed" << std::endl;
        }
        else if (event.key.code == KeyLane3)
        {
            drawer->ChangeTexture(3);
            std::cout << "KeyLane 3 pressed" << std::endl;
        }
        else if (event.key.code == KeyLane4)
        {
            drawer->ChangeTexture(4);
            std::cout << "KeyLane 4 pressed" << std::endl;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == KeyLane1)
            drawer->ResetTexture(1);
        else if (event.key.code == KeyLane2)
            drawer->ResetTexture(2);
        else if (event.key.code == KeyLane3)
            drawer->ResetTexture(3);
        else if (event.key.code == KeyLane4)
            drawer->ResetTexture(4);

    }
}
;