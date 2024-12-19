#include "TitleScreen.h"

TitleScreen::TitleScreen()
{
	if (!waluigipinball.openFromFile("resources/music/WalugisPinball IntroCut.wav"))
		std::cout << "Error loading sound!!";
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::StartingScreen()
{
	if (isPlaying) {
		waluigipinball.play();
		isPlaying = false;
	}
}
