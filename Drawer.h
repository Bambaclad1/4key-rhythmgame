#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include "Arrow.h"
#include "Resources.h"
#include <iostream>


class Drawer
{
public:
	Drawer();

	void Draw(sf::RenderWindow& MainWindow, float deltaTime);
	void SetupTextures();
	void SetupText();
	void Update(float deltaTime);
	void BoundingBox(sf::RenderWindow& MainWindow);

	void ChangeTexture(int lane);
	void ResetTexture(int lane);

	bool IsLeftPressed() const { return LeftPressed; }
	bool IsDownPressed() const { return DownPressed; }
	bool IsUpPressed() const { return UpPressed; }
	bool IsRightPressed() const { return RightPressed; }

	void SetLeftPressed(bool pressed) { LeftPressed = pressed; }
	void SetDownPressed(bool pressed) { DownPressed = pressed; }
	void SetUpPressed(bool pressed) { UpPressed = pressed; }
	void SetRightPressed(bool pressed) { RightPressed = pressed; }

private:
	const sf::Texture* arrowUpText; // Normal Arrows, bar arrows.
	const sf::Texture arrowDownText;
	const sf::Texture arrowLeftText;
	const sf::Texture arrowRightText;

	const sf::Texture* arrowUpKDText; // Pressed down arrows.
	const sf::Texture* arrowDownKDText;
	const sf::Texture* arrowRightKDText; 
	const sf::Texture* arrowLeftKDText;  

	 sf::Sprite arrowUp;
	 sf::Sprite arrowDown;
	 sf::Sprite arrowLeft;
	 sf::Sprite arrowRight;

	sf::Font nerdfont;
	sf::Text text;
	sf::Text scoreJudge;
	sf::Text Score;

	int ScoreCounter = 0;

	bool LeftPressed = false;
	bool DownPressed = false;
	bool UpPressed = false;
	bool RightPressed = false;

	sf::Clock timer;
	sf::Clock timeFrame;
	bool timerStarted = false;

	bool LeftIsTrue = true;
	bool DownIsTrue = true;
	bool UpIsTrue = true;
	bool RightIsTrue = true;
};
