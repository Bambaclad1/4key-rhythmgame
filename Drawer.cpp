#include "Drawer.h"

Drawer::Drawer()
{
	arrowClass = std::make_unique<Arrow>(); // instantiate the arrowClass
	std::cout << "Drawer loaded! + arrow Class Instantiated!" << std::endl;
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

	arrowClass.InitSprite();
	arrowClass.GetVectorArrows();
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
	for (int i = 0; i < afallingarrows.size(); i++)
	{
		MainWindow.draw(afallingarrows[i]);
	}
	MainWindow.draw(arrowUp);
	MainWindow.draw(arrowDown);
	MainWindow.draw(arrowLeft);
	MainWindow.draw(arrowRight);

	arrowClass.testsong(MainWindow);

	arrowClass.draw(MainWindow, statesdummy);

	arrowClass.Update(MainWindow, deltaTime);

	MainWindow.draw(scoreJudge);
	MainWindow.draw(Score), Score.setString(std::to_string(ScoreCounter));
}
void Drawer::Update(float deltaTime)
{
	const float speed = 800.0f;
	float currentTimeStamp = timeFrame.getElapsedTime().asMilliseconds();
}

void Drawer::BoundingBox(sf::RenderWindow& MainWindow)
{
	sf::RectangleShape boundingBox;
	afallingarrows = arrowClass.GetVectorArrows();

	boundingBox.setSize(sf::Vector2f(arrowUp.getGlobalBounds().width, arrowUp.getGlobalBounds().height));
	boundingBox.setOutlineColor(sf::Color::Red);
	boundingBox.setOutlineThickness(1.0f);
	boundingBox.setFillColor(sf::Color::Transparent);

	auto drawBoundingBox = [&](const sf::Sprite& arrow) {
		boundingBox.setPosition(arrow.getGlobalBounds().left, arrow.getGlobalBounds().top);
		MainWindow.draw(boundingBox);
		};

	for (int i = 0; i < afallingarrows.size(); i++)
	{
		drawBoundingBox(afallingarrows[i]);
	}
	drawBoundingBox(arrowUp);
	drawBoundingBox(arrowDown);
	drawBoundingBox(arrowLeft);
	drawBoundingBox(arrowRight);

	MainWindow.draw(boundingBox);

	for (int i = 0; i < afallingarrows.size();)
	{
		bool arrowRemoved = false;

		if (IsLeftPressed()) {
			if (afallingarrows[i].getGlobalBounds().intersects(arrowLeft.getGlobalBounds()))
			{
				std::cout << "clickLeft!\n";
				SetLeftPressed(false);
				arrowRemoved = true;
				RemoveFirstArrowInMap = true;
			}
		}
		else if (IsDownPressed()) {
			if (afallingarrows[i].getGlobalBounds().intersects(arrowDown.getGlobalBounds()))
			{
				std::cout << "clickDown!\n";
				SetDownPressed(false);
				arrowRemoved = true;
				RemoveFirstArrowInMap = true;
			}
		}
		else if (IsUpPressed()) {
			if (afallingarrows[i].getGlobalBounds().intersects(arrowUp.getGlobalBounds()))
			{
				std::cout << "clickUp!\n";
				SetUpPressed(false);
				arrowRemoved = true;
				RemoveFirstArrowInMap = true;
			}
		}
		else if (IsRightPressed()) {
			if (afallingarrows[i].getGlobalBounds().intersects(arrowRight.getGlobalBounds()))
			{
				std::cout << "clickRight!\n";
				SetRightPressed(false);
				arrowRemoved = true;
				RemoveFirstArrowInMap = true;
			}
		}

		// Only increment the index if no arrow was removed
		if (!arrowRemoved) {
			++i;
		}

		if (RemoveFirstArrowInMap) {
			arrowClass.RemoveFirstArrowInMap();
			RemoveFirstArrowInMap = false;
		}
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