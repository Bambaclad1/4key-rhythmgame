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
		!arrowRightKDText.loadFromFile("resources/gamesprites/arrowRightKD.png") || 
		!arrowUpFText.loadFromFile("resources/gamesprites/arrowUp.png") ||
		!arrowDownFText.loadFromFile("resources/gamesprites/arrowDown.png") ||
		!arrowLeftFText.loadFromFile("resources/gamesprites/arrowLeft.png") ||
		!arrowRightFText.loadFromFile("resources/gamesprites/arrowRight.png"))

	{
		std::cout << "Error! Unable to load textures!" << std::endl;
	}

	arrowUpText.setSmooth(true), arrowDownText.setSmooth(true), arrowLeftText.setSmooth(true), arrowRightText.setSmooth(true);
	arrowUpKDText.setSmooth(true), arrowDownKDText.setSmooth(true), arrowLeftKDText.setSmooth(true), arrowRightKDText.setSmooth(true);

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


	arrow1.setScale(0.5f, 0.5f), arrow2.setScale(0.5f, 0.5f), arrow3.setScale(0.5f, 0.5f), arrow4.setScale(0.5f, 0.5f);
	arrow1.setPosition(750, 0), arrow2.setPosition(600, 0), arrow3.setPosition(450, 0), arrow4.setPosition(900, 0);

	arrow1.setTexture(arrowUpFText);
	arrow2.setTexture(arrowDownFText);
	arrow3.setTexture(arrowLeftFText);
	arrow4.setTexture(arrowRightFText);

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

	MainWindow.draw(arrow1);
	MainWindow.draw(arrow2);
	MainWindow.draw(arrow3);
	MainWindow.draw(arrow4);
}

void Drawer::Update(float deltaTime)
{
	const float speed = 500.0f; 

	// Move the arrows down
	arrow1.move(0, speed * deltaTime);
	arrow2.move(0, speed * deltaTime);
	arrow3.move(0, speed * deltaTime);
	arrow4.move(0, speed * deltaTime);

	// Reset arrows to the top if they go off-screen (example)
	if (arrow1.getPosition().y > 900) arrow1.setPosition(750, 0);
	if (arrow2.getPosition().y > 900) arrow2.setPosition(600, 0);
	if (arrow3.getPosition().y > 900) arrow3.setPosition(450, 0);
	if (arrow4.getPosition().y > 900) arrow4.setPosition(900, 0);
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