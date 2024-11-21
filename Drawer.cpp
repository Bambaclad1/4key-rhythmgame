#include "Drawer.h"

void Drawer::SetupTextures()
{
	if (!arrowUpText.loadFromFile("resources/gamesprites/arrowUpD.png") ||
		!arrowDownText.loadFromFile("resources/gamesprites/arrowDownD.png") ||
		!arrowLeftText.loadFromFile("resources/gamesprites/arrowLeftD.png") ||
		!arrowRightText.loadFromFile("resources/gamesprites/arrowRightD.png") ||
		!arrowUpKDText.loadFromFile("resources/gamesprites/arrowUpKD.png") ||
		!arrowDownKDText.loadFromFile("resources/gamesprites/arrowDownKD.png") ||
		!arrowLeftKDText.loadFromFile("resources/gamesprites/arrowLeftKD.png") ||
		!arrowRightKDText.loadFromFile("resources/gamesprites/arrowRightKD.png"))

	{
		std::cout << "Error! Unable to load textures!" << std::endl;
	}

	arrowUpText.setSmooth(true);
	arrowDownText.setSmooth(true);
	arrowLeftText.setSmooth(true);
	arrowRightText.setSmooth(true);

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
	text.setString("D F J K - Keybinds for Lanes.");
	text.setCharacterSize(16);
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
	boundingBox.setOutlineColor(sf::Color::Red);
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

void Drawer::ChangeTexture(int lane)
{
	if (lane == 1) {
		arrowLeft.setTexture(arrowLeftKDText);
	}
	else if (lane == 2) {
		arrowDown.setTexture(arrowDownKDText);
	}
	else if (lane == 3) {
		arrowUp.setTexture(arrowUpKDText);
	}
	else if (lane == 4) {
		arrowRight.setTexture(arrowRightKDText);
	}
}
void Drawer::ResetTexture(int lane)
{
	switch (lane)
	{
	case 1:
		arrowLeft.setTexture(arrowLeftText, true);
		break;
	case 2:
		arrowDown.setTexture(arrowDownText);
		break;
	case 3:
		arrowUp.setTexture(arrowUpText);
		break;
	case 4:
		arrowRight.setTexture(arrowRightText);
		break;
	}
}