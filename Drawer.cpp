#include "Drawer.h"

void Drawer::SetupTextures()
{
	if (!arrowUpText.loadFromFile("resources/gamesprites/arrowUp.png") ||
		!arrowDownText.loadFromFile("resources/gamesprites/arrowDown.png") ||
		!arrowLeftText.loadFromFile("resources/gamesprites/arrowLeft.png") ||
		!arrowRightText.loadFromFile("resources/gamesprites/arrowRight.png"))
	{
		std::cout << "Error! Unable to load textures!" << std::endl;
	}

	arrowUpText.setSmooth(true), arrowDownText.setSmooth(true), arrowLeftText.setSmooth(true), arrowRightText.setSmooth(true);

	arrowLeft.setPosition(450, 700);
	arrowLeft.setScale(0.5f, 0.5f);

	arrowDown.setPosition(600, 700);
	arrowDown.setScale(0.5f, 0.5f);

	arrowUp.setPosition(750, 700);
	arrowUp.setScale(0.5f, 0.5f);

	arrowRight.setPosition(900, 700);
	arrowRight.setScale(0.5f, 0.5f);

	arrowUp.setTexture(arrowUpText);
	arrowDown.setTexture(arrowDownText);
	arrowLeft.setTexture(arrowLeftText);
	arrowRight.setTexture(arrowRightText);
}

void Drawer::SetupText()
{
	if (!nerdfont.loadFromFile("resources/fonts/0xProtoNerdFont-Regular.ttf"))
	{
		std::cout << "Error! Unable to load Fonts!!" << std::endl;
	}
	text.setFont(nerdfont);
	text.setString("Hello World!.");
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Black);

}

void Drawer::Draw(sf::RenderWindow& MainWindow)
{
	MainWindow.draw(arrowUp);
	MainWindow.draw(arrowDown);
	MainWindow.draw(arrowLeft);
	MainWindow.draw(arrowRight);
	MainWindow.draw(text);


}
