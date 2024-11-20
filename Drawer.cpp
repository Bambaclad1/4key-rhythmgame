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

	sf::Vector2u textureSize = arrowUpText.getSize();
	sf::Vector2f scale = arrowUp.getScale();

	float scaledWidth = textureSize.x * scale.x;
	float scaledHeight = textureSize.y * scale.y;

	std::cout << "Scaled Width: " << scaledWidth << ", Scaled Height: " << scaledHeight << std::endl;


}

void Drawer::Draw(sf::RenderWindow& MainWindow)
{
	MainWindow.draw(arrowUp);
	MainWindow.draw(arrowDown);
	MainWindow.draw(arrowLeft);
	MainWindow.draw(arrowRight);


}

void Drawer::BoundingBox(sf::RenderWindow& MainWindow)
{
	sf::RectangleShape boundingBox;
	boundingBox.setSize(sf::Vector2f(arrowUp.getGlobalBounds().width, arrowUp.getGlobalBounds().height));
	boundingBox.setOutlineColor(sf::Color::Red); // Set outline color to make it visible
	boundingBox.setOutlineThickness(1.0f);
	boundingBox.setFillColor(sf::Color::Transparent);

	// Draw Bounding Boxes
	boundingBox.setPosition(arrowUp.getGlobalBounds().left, arrowUp.getGlobalBounds().top);
	MainWindow.draw(boundingBox);

	boundingBox.setPosition(arrowDown.getGlobalBounds().left, arrowDown.getGlobalBounds().top);
	MainWindow.draw(boundingBox);

	boundingBox.setPosition(arrowLeft.getGlobalBounds().left, arrowLeft.getGlobalBounds().top);
	MainWindow.draw(boundingBox);

	boundingBox.setPosition(arrowRight.getGlobalBounds().left, arrowRight.getGlobalBounds().top);
	MainWindow.draw(boundingBox);

	MainWindow.draw(text);
}
