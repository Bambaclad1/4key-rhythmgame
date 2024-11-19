#include "Loader.h"


void Loader::Preload()
{
	arrowUp.loadFromFile("resources/gamesprites/image.png"), arrowUp.setSmooth(true);
	arrowDown.loadFromFile("resources/gamesprites/image.png"), arrowDown.setSmooth(true);
	arrowLeft.loadFromFile("resources/gamesprites/image.png"), arrowLeft.setSmooth(true);
	arrowRight.loadFromFile("resources/gamesprites/image.png"), arrowRight.setSmooth(true);

}
