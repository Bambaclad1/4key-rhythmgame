#include "Arrow.h"

Arrow::Arrow() // something
{
	std::cout << "Arrow loaded!\n";
}

Arrow::~Arrow()
{
}

void Arrow::InitSprite() {
	if (!arrowLeftFalling.loadFromFile("resources/gamesprites/arrowLeft.png") ||
		!arrowUpFalling.loadFromFile("resources/gamesprites/arrowUp.png") ||
		!arrowDownFalling.loadFromFile("resources/gamesprites/arrowDown.png") ||
		!arrowRightFalling.loadFromFile("resources/gamesprites/arrowRight.png"))
	{
		std::cout << "Error! Unable to load Arrow.h files! Check resources/gamesprites if the files are there!" << std::endl;
	}
	// Textures loaded? Cool, let's get on going.

	arrow.setPosition(500, 500);
	arrow.setTexture(arrowLeftFalling);
	
}

void Arrow::Update(float deltaTime)
{
	const float speed = 500.0f;

	arrow.move(0, speed * deltaTime);
}

void Arrow::testsong(sf::RenderWindow& MainWindow)
{
	MainWindow.draw(arrow);
}