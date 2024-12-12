#include "ControllerLeft.h"

ControllerLeft::ControllerLeft()
{
	if (!arrowControllerTextureLeft.loadFromFile("resources/gamesprites/arrowLeft.png")) {
		std::cout << "Unable to load ArrowControllerLeft! Don't make a issue on github, fix it yourself! /j" << std::endl;
	}
	arrowControllerTextureLeft.setSmooth(true);
	
	arrowControllerLeft.setPosition(450, 700);
	arrowControllerLeft.setScale(0.5f, 0.5f);

	arrowControllerLeft.setTexture(arrowControllerTextureLeft);
}

ControllerLeft::~ControllerLeft()
{
}
