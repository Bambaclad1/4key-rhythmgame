#include "Arrow.h"

Arrow::Arrow() // something
{
}

Arrow::~Arrow()
{
}

void Arrow::InitSprite() {
	if (!arrowLeftFalling.loadFromFile("resources/gamesprites/arrowUp.png") ||
		!arrowUpFalling.loadFromFile("resources/gamesprites/arrowDown.png") ||
		!arrowDownFalling.loadFromFile("resources/gamesprites/arrowLeft.png") ||
		!arrowRightFalling.loadFromFile("resources/gamesprites/arrowRight.png"))
	{
		std::cout << "Error! Unable to load Arrow.h files! Check resources/gamesprites if the files are there!" << std::endl;
	}
	// Textures loaded? Cool, let's get on going.

	arrow.setPosition(500, 500);
}

void Arrow::testsong()
{
}