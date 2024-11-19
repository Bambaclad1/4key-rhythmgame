#include "Drawer.h"

void Drawer::Setup()
{
	if (!arrowUpText.loadFromFile("resources/gamesprites/arrowUp.png") ||
		!arrowDownText.loadFromFile("resources/gamesprites/arrowDown.png") ||
		!arrowLeftText.loadFromFile("resources/gamesprites/arrowLeft.png") ||
		!arrowRightText.loadFromFile("resources/gamesprites/arrowRight.png"))
	{
		std::cerr << "Error! Unable to load textures!" << std::endl;
	}

	arrowUp.setPosition(250, 600);

	arrowUp.setScale(0.6f, 0.6f);
	arrowUp.setTexture(arrowUpText);
	arrowDown.setTexture(arrowDownText);
	arrowLeft.setTexture(arrowLeftText);
	arrowRight.setTexture(arrowRightText);



}

void Drawer::Draw(sf::RenderWindow& MainWindow)
{
	MainWindow.draw(arrowUp);
	MainWindow.draw(arrowDown);
	MainWindow.draw(arrowLeft);
	MainWindow.draw(arrowRight);


}
