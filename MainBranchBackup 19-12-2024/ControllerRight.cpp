#include "ControllerRight.h"

ControllerRight::ControllerRight()
{
	if (!arrowControllerTextureRight.loadFromFile("resources/gamesprites/arrowRight.png")) {
		std::cout << "Unable to load ArrowControllerRight! Don't make a issue on github, fix it yourself! /j" << std::endl;
	}
	arrowControllerTextureRight.setSmooth(true);

	arrowControllerRight.setPosition(900, 700);
	arrowControllerRight.setScale(0.5f, 0.5f);

	arrowControllerRight.setTexture(arrowControllerTextureRight);
}

ControllerRight::~ControllerRight()
{
}
