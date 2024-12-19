#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>	
class TitleScreen
{
public:
	TitleScreen();
	~TitleScreen();

	void StartingScreen();
private:
	sf::SoundBuffer IntroMusicBuffer;
	sf::Sound IntroMusic;

	sf::Music waluigipinball;

	bool isPlaying = true;

	sf::Clock gameclock;
};

