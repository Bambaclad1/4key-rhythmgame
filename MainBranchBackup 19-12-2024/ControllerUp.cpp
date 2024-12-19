#include "ControllerUp.h"

ControllerUp::ControllerUp()
{
	if (!arrowControllerTextureUp.loadFromFile("resources/gamesprites/arrowUp.png")) {
		std::cout << "Unable to load ArrowControllerUp! Don't make a issue on github, fix it yourself! /j" << std::endl;
	}
	arrowControllerTextureUp.setSmooth(true);

	arrowControllerUp.setPosition(750, 700);
	arrowControllerUp.setScale(0.5f, 0.5f);

	arrowControllerUp.setTexture(arrowControllerTextureUp);
}

ControllerUp::~ControllerUp()
{
}
