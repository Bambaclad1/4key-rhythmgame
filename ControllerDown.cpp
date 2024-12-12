#include "ControllerDown.h"

ControllerDown::ControllerDown()
{
	if (!arrowControllerTextureDown.loadFromFile("resources/gamesprites/arrowDown.png")) {
		std::cout << "Unable to load ArrowControllerDown! Don't make a issue on github, fix it yourself! /j" << std::endl;
	}
	arrowControllerTextureDown.setSmooth(true);

	arrowControllerDown.setPosition(600, 700);
	arrowControllerDown.setScale(0.5f, 0.5f);

	arrowControllerDown.setTexture(arrowControllerTextureDown);
}

ControllerDown::~ControllerDown()
{
}
