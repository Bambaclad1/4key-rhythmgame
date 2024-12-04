#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include <iostream>
class Drawer
{
public:
	Drawer();
	void SetupTextures();
	void SetupText();
	void Draw(sf::RenderWindow& MainWindow);
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
	sf::Texture arrowUpText; // Normal Arrows, bar arrows.
	sf::Texture arrowDownText;
	sf::Texture arrowLeftText;
	sf::Texture arrowRightText;

	sf::Texture arrowUpKDText; // Pressed down arrows.
	sf::Texture arrowDownKDText;
	sf::Texture arrowLeftKDText;
	sf::Texture arrowRightKDText;

	sf::Texture arrowUpFText; // Falling down arrows (instantiate them.)
	sf::Texture arrowDownFText;
	sf::Texture arrowLeftFText;
	sf::Texture arrowRightFText;

	sf::Sprite arrowUp;
	sf::Sprite arrowDown;
	sf::Sprite arrowLeft;
	sf::Sprite arrowRight;

	sf::Sprite arrow1;	//lekkere benaming dit
	sf::Sprite arrow2;	//down
	sf::Sprite arrow3;	//left
	sf::Sprite arrow4;	//right

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
