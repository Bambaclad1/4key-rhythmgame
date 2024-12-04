#include "Drawer.h"

Drawer::Drawer()
{
	std::cout << "Drawer loaded!\n";
}

void Drawer::SetupTextures()
{
	if (!arrowUpText.loadFromFile("resources/gamesprites/arrowUpD.png") ||
		!arrowDownText.loadFromFile("resources/gamesprites/arrowDownD.png") ||
		!arrowLeftText.loadFromFile("resources/gamesprites/arrowLeftD.png") ||
		!arrowRightText.loadFromFile("resources/gamesprites/arrowRightD.png") ||
		!arrowUpKDText.loadFromFile("resources/gamesprites/arrowUpKD.png") ||
		!arrowDownKDText.loadFromFile("resources/gamesprites/arrowDownKD.png") ||
		!arrowLeftKDText.loadFromFile("resources/gamesprites/arrowLeftKD.png") ||
		!arrowRightKDText.loadFromFile("resources/gamesprites/arrowRightKD.png"))

	{
		std::cout << "Error! Unable to load Drawer.h files! Check resources/gamesprites if the files are there!" << std::endl;
	}

	arrowUpText.setSmooth(true), arrowDownText.setSmooth(true), arrowLeftText.setSmooth(true), arrowRightText.setSmooth(true);
	arrowUpKDText.setSmooth(true), arrowDownKDText.setSmooth(true), arrowLeftKDText.setSmooth(true), arrowRightKDText.setSmooth(true);

	arrowLeft.setPosition(450, 700);
	arrowLeft.setScale(0.5f, 0.5f);

	arrowDown.setPosition(600, 700);
	arrowDown.setScale(0.5f, 0.5f);

	arrowUp.setPosition(750, 700);
	arrowUp.setScale(0.5f, 0.5f);

	arrowRight.setPosition(900, 700);
	arrowRight.setScale(0.5f, 0.5f);

	arrowUp.setTexture(arrowUpText);
	arrowDown.setTexture(arrowDownText);
	arrowLeft.setTexture(arrowLeftText);
	arrowRight.setTexture(arrowRightText);

	arrow1.setScale(0.5f, 0.5f), arrow2.setScale(0.5f, 0.5f), arrow3.setScale(0.5f, 0.5f), arrow4.setScale(0.5f, 0.5f);
	arrow1.setPosition(750, 0), arrow2.setPosition(600, 0), arrow3.setPosition(450, 0), arrow4.setPosition(900, 0);

	arrow1.setTexture(arrowUpFText);
	arrow2.setTexture(arrowDownFText);
	arrow3.setTexture(arrowLeftFText);
	arrow4.setTexture(arrowRightFText);
}

void Drawer::SetupText()
{
	if (!nerdfont.loadFromFile("resources/fonts/0xProtoNerdFont-Regular.ttf"))
	{
		std::cout << "Error! Unable to load Fonts!!" << std::endl;
	}
	text.setFont(nerdfont);
	text.setString("D F J K - Keybinds for Lanes.");
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::Black);

	scoreJudge.setFont(nerdfont);
	scoreJudge.setCharacterSize(52);

	scoreJudge.setPosition(600, 550);

	Score.setFont(nerdfont);
	Score.setCharacterSize(60);
	Score.setFillColor(sf::Color::Magenta);
	Score.setPosition(100, 250);
}

void Drawer::Draw(sf::RenderWindow& MainWindow, float deltaTime)
{
	MainWindow.draw(arrowUp);
	MainWindow.draw(arrowDown);
	MainWindow.draw(arrowLeft);
	MainWindow.draw(arrowRight);

	arrowClass.InitSprite();
	arrowClass.Update(deltaTime);
	arrowClass.testsong(MainWindow);

	MainWindow.draw(arrow1);
	MainWindow.draw(arrow2);
	MainWindow.draw(arrow3);
	MainWindow.draw(arrow4);
	MainWindow.draw(scoreJudge);
	MainWindow.draw(Score), Score.setString(std::to_string(ScoreCounter));
}

void Drawer::Update(float deltaTime)
{
	const float speed = 800.0f;

	arrow1.move(0, speed * deltaTime);
	arrow2.move(0, speed * deltaTime);
	arrow3.move(0, speed * deltaTime);
	arrow4.move(0, speed * deltaTime);

	if (arrow1.getPosition().y > 900) arrow1.setPosition(750, -150), UpIsTrue = true;
	if (arrow2.getPosition().y > 900) arrow2.setPosition(600, -150), DownIsTrue = true;
	if (arrow3.getPosition().y > 900) arrow3.setPosition(450, -150), LeftIsTrue = true;
	if (arrow4.getPosition().y > 900) arrow4.setPosition(900, -150), RightIsTrue = true;

	float currentTimeStamp = timeFrame.getElapsedTime().asMilliseconds();
}

void Drawer::BoundingBox(sf::RenderWindow& MainWindow)
{
	sf::RectangleShape boundingBox;
	boundingBox.setSize(sf::Vector2f(arrowUp.getGlobalBounds().width, arrowUp.getGlobalBounds().height));
	boundingBox.setOutlineColor(sf::Color::Red);
	boundingBox.setOutlineThickness(1.0f);
	boundingBox.setFillColor(sf::Color::Transparent);

	auto drawBoundingBox = [&](const sf::Sprite& arrow) {
		boundingBox.setPosition(arrow.getGlobalBounds().left, arrow.getGlobalBounds().top);
		MainWindow.draw(boundingBox);
	};

	drawBoundingBox(arrowUp);
	drawBoundingBox(arrowDown);
	drawBoundingBox(arrowLeft);
	drawBoundingBox(arrowRight);
	drawBoundingBox(arrow1);
	drawBoundingBox(arrow2);
	drawBoundingBox(arrow3);
	drawBoundingBox(arrow4);

	if (timerStarted) {
		float elapsed = timer.getElapsedTime().asSeconds();
		if (elapsed <= 0.1f) {
			float scaleFactor = 1.0f + elapsed * 3.0f;
			scoreJudge.setScale(scaleFactor, scaleFactor);
		}
		else {
			scoreJudge.setScale(1.0f, 1.0f);
			scoreJudge.setString("");
			timerStarted = false;
		}
	}
	float arrowY = arrow3.getPosition().y;
	if (LeftPressed) {
		float arrowX = arrow3.getPosition().x;
		float arrowY = arrow3.getPosition().y;

		if (arrowY >= 600 && arrowY <= 750) {
			if (arrowY >= 670 && arrowY <= 730)
			{
				scoreJudge.setFillColor(sf::Color::Color(85, 255, 255));
				scoreJudge.setString("Perfect!");
				arrow3.setPosition(450, -150);
				ScoreCounter = ScoreCounter + 300;
				LeftPressed = false;
			}
			else if (arrowY >= 650 && arrowY <= 670)
			{
				scoreJudge.setFillColor(sf::Color::Color(68, 255, 68));
				scoreJudge.setString("Good!");
				arrow3.setPosition(450, -150);
				ScoreCounter = ScoreCounter + 200;
				LeftPressed = false;
			}
			else if (arrowY = 600 && arrowY <= 650) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 68));
				scoreJudge.setString("Ok!");
				arrow3.setPosition(450, -150);
				ScoreCounter = ScoreCounter + 100;
				LeftPressed = false;
			}
			else if (arrowY >= 750 && arrowY <= 750) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 69));
				scoreJudge.setString("Ok!");
				arrow3.setPosition(450, -150);
				LeftPressed = false;
			}
			else if (arrowY >= 900 && arrowY <= 750)
			{
				scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
				scoreJudge.setString("Miss!");
				ScoreCounter = ScoreCounter - 100;
				LeftPressed = false;
			}

			timer.restart();
			timerStarted = true;
		}
	}
	if (DownPressed)
	{
		float arrowX = arrow2.getPosition().x;
		float arrowY = arrow2.getPosition().y;

		if (arrowY >= 600 && arrowY <= 750) {
			if (arrowY >= 670 && arrowY <= 730)
			{
				scoreJudge.setFillColor(sf::Color::Color(85, 255, 255));
				scoreJudge.setString("Perfect!");
				arrow2.setPosition(600, -150);
				ScoreCounter = ScoreCounter + 300;
				DownPressed = false;
			}
			else if (arrowY >= 650 && arrowY <= 670)
			{
				scoreJudge.setFillColor(sf::Color::Color(68, 255, 68));
				scoreJudge.setString("Good!");
				arrow2.setPosition(600, -150);
				ScoreCounter = ScoreCounter + 200;
				DownPressed = false;
			}
			else if (arrowY = 600 && arrowY <= 650) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 68));
				scoreJudge.setString("Ok!");
				arrow2.setPosition(600, -150);
				ScoreCounter = ScoreCounter + 100;
				DownPressed = false;
			}
			else if (arrowY >= 750 && arrowY <= 750) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 69));
				scoreJudge.setString("Ok!");
				arrow2.setPosition(600, -150);
				DownPressed = false;
			}
			else if (arrowY >= 900 && arrowY <= 750)
			{
				scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
				scoreJudge.setString("Miss!");
				ScoreCounter = ScoreCounter - 100;
				DownPressed = false;
			}

			timer.restart();
			timerStarted = true;
		}
	}
	if (UpPressed)
	{
		float arrowX = arrow1.getPosition().x;
		float arrowY = arrow1.getPosition().y;

		if (arrowY >= 600 && arrowY <= 750) {
			if (arrowY >= 670 && arrowY <= 730)
			{
				scoreJudge.setFillColor(sf::Color::Color(85, 255, 255));
				scoreJudge.setString("Perfect!");
				arrow1.setPosition(750, -150);
				ScoreCounter = ScoreCounter + 300;
				UpPressed = false;
			}
			else if (arrowY >= 650 && arrowY <= 670)
			{
				scoreJudge.setFillColor(sf::Color::Color(68, 255, 68));
				scoreJudge.setString("Good!");
				arrow1.setPosition(750, -150);
				ScoreCounter = ScoreCounter + 200;
				UpPressed = false;
			}
			else if (arrowY = 600 && arrowY <= 650) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 68));
				scoreJudge.setString("Ok!");
				arrow1.setPosition(750, -150);
				ScoreCounter = ScoreCounter + 100;
				UpPressed = false;
			}
			else if (arrowY >= 750 && arrowY <= 750) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 69));
				scoreJudge.setString("Ok!");
				arrow1.setPosition(750, -150);
				UpPressed = false;
			}
			else if (arrowY >= 900 && arrowY <= 750)
			{
				scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
				scoreJudge.setString("Miss!");
				ScoreCounter = ScoreCounter - 100;
				UpPressed = false;
			}

			timer.restart();
			timerStarted = true;
		}
	}
	if (RightPressed)
	{
		float arrowX = arrow4.getPosition().x;
		float arrowY = arrow4.getPosition().y;

		if (arrowY >= 600 && arrowY <= 750) {
			if (arrowY >= 670 && arrowY <= 730)
			{
				scoreJudge.setFillColor(sf::Color::Color(85, 255, 255));
				scoreJudge.setString("Perfect!");
				arrow4.setPosition(900, -150);
				ScoreCounter = ScoreCounter + 300;
				RightPressed = false;
			}
			else if (arrowY >= 650 && arrowY <= 670)
			{
				scoreJudge.setFillColor(sf::Color::Color(68, 255, 68));
				scoreJudge.setString("Good!");
				arrow4.setPosition(900, -150);
				ScoreCounter = ScoreCounter + 200;
				RightPressed = false;
			}
			else if (arrowY = 600 && arrowY <= 650) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 68));
				scoreJudge.setString("Ok!");
				arrow4.setPosition(900, -150);
				ScoreCounter = ScoreCounter + 100;
				RightPressed = false;
			}
			else if (arrowY >= 750 && arrowY <= 750) {
				scoreJudge.setFillColor(sf::Color::Color(255, 255, 69));
				scoreJudge.setString("Ok!");
				arrow4.setPosition(900, -150);
				RightPressed = false;
			}
			else if (arrowY >= 900 && arrowY <= 750)
			{
				scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
				scoreJudge.setString("Miss!");
				ScoreCounter = ScoreCounter - 100;
				RightPressed = false;
			}

			timer.restart();
			timerStarted = true;
		}
	}

	float arrowLeftY = arrow3.getPosition().y;
	if (arrowLeftY >= 800 && LeftIsTrue == true)
	{
		scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
		scoreJudge.setString("Miss!");
		ScoreCounter = ScoreCounter - 100;
		LeftIsTrue = false;
	}

	float arrowDownY = arrow2.getPosition().y;
	if (arrowDownY >= 800 && DownIsTrue == true)
	{
		scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
		scoreJudge.setString("Miss!");
		ScoreCounter = ScoreCounter - 100;
		DownIsTrue = false;
	}

	float arrowUpY = arrow1.getPosition().y;
	if (arrowUpY >= 800 && UpIsTrue == true)
	{
		scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
		scoreJudge.setString("Miss!");
		ScoreCounter = ScoreCounter - 100;
		UpIsTrue = false;
	}

	float arrowRightY = arrow4.getPosition().y;
	if (arrowRightY >= 800 && RightIsTrue == true)
	{
		scoreJudge.setFillColor(sf::Color::Color(255, 68, 85));
		scoreJudge.setString("Miss!");
		ScoreCounter = ScoreCounter - 100;
		RightIsTrue = false;
	}

	MainWindow.draw(text);
}

void Drawer::ChangeTexture(int lane)
{
	if (lane == 1) {
		arrowLeft.setTexture(arrowLeftKDText);
	}
	else if (lane == 2) {
		arrowDown.setTexture(arrowDownKDText);
	}
	else if (lane == 3) {
		arrowUp.setTexture(arrowUpKDText);
	}
	else if (lane == 4) {
		arrowRight.setTexture(arrowRightKDText);
	}
}
void Drawer::ResetTexture(int lane)
{
	switch (lane)
	{
	case 1:
		arrowLeft.setTexture(arrowLeftText);
		break;
	case 2:
		arrowDown.setTexture(arrowDownText);
		break;
	case 3:
		arrowUp.setTexture(arrowUpText);
		break;
	case 4:
		arrowRight.setTexture(arrowRightText);
		break;
	}
}