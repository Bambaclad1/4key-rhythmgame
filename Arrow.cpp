#include "Arrow.h"

Arrow::Arrow() : speed(500.0f)  // Use member initializer to set speed.
{
	std::cout << "Arrow loaded!\n";
}

Arrow::~Arrow()
{
}

void Arrow::InitSprite() {
	if (!arrowLeftFalling.loadFromFile("resources/gamesprites/arrowLeft.png") ||
		!arrowUpFalling.loadFromFile("resources/gamesprites/arrowUp.png") ||
		!arrowDownFalling.loadFromFile("resources/gamesprites/arrowDown.png") ||
		!arrowRightFalling.loadFromFile("resources/gamesprites/arrowRight.png"))
	{
		std::cout << "Error! Unable to load Arrow.h files! Check resources/gamesprites if the files are there!" << std::endl;
	}
	// Textures loaded? Cool, let's get on going.

	// Lets make them smooth first though, otherwise they will appear "mushy"
	arrowLeftFalling.setSmooth(true), arrowUpFalling.setSmooth(true), arrowDownFalling.setSmooth(true), arrowRightFalling.setSmooth(true);

	//Done! Now lets tell the code what the properties of the arrow are!
	arrowSprite.setPosition(450, 100);
	arrowSprite.setTexture(arrowLeftFalling);

	arrowSprite.setScale(0.5f, 0.5f);
	/*arrowLeft.setPosition(450, 700);
	arrowDown.setPosition(600, 700);
	arrowUp.setPosition(750, 700);
	arrowRight.setPosition(900, 700);*/

	GameTimer.restart();

}

void Arrow::Update(sf::RenderWindow& MainWindow, float deltaTime)
{

	arrowSprite.move(0, speed * deltaTime);

	float mss = GameTimer.getElapsedTime().asSeconds();
	std::cout << mss;
	std::pair<float, ArrowDirection::dirs> nextAction = GetNextAction();
	if (mss > nextAction.first) {
		std::cout << "Hier komt de arrow spawn, de arrow is" << std::endl;
		if (nextAction.second == 1) {
			std::cout << "left!";
			arrowSprite.setTexture(arrowLeftFalling);
			arrowSprite.setPosition(450, 700);
		}
		else if (nextAction.second == 2) {
			std::cout << "up!";
			arrowSprite.setTexture(arrowUpFalling);
			arrowSprite.setPosition(600, 700);
		}
		else if (nextAction.second == 3) {
			std::cout << "down!";
			arrowSprite.setTexture(arrowDownFalling);
			arrowSprite.setPosition(750, 700);
		}
		else if (nextAction.second == 4) {
			std::cout << "right!";
			arrowSprite.setTexture(arrowRightFalling);
			arrowSprite.setPosition(900, 700);
		}
		nextAction = GetNextAction();
	}
	MainWindow.draw(arrowSprite);
}

void Arrow::BoundingBoxCollision(sf::RenderWindow& MainWindow)
{
	sf::RectangleShape boundingBox;
	boundingBox.setSize(sf::Vector2f(arrowSprite.getGlobalBounds().width, arrowSprite.getGlobalBounds().height));
	boundingBox.setOutlineColor(sf::Color::Red);
	boundingBox.setOutlineThickness(1.0f);
	boundingBox.setFillColor(sf::Color::Transparent);

	auto drawBoundingBox = [&](const sf::Sprite& arrow) {
		boundingBox.setPosition(arrow.getGlobalBounds().left, arrow.getGlobalBounds().top);
		MainWindow.draw(boundingBox);
		};

	drawBoundingBox(arrowSprite);
}

void Arrow::testsong(sf::RenderWindow& MainWindow)
{
	//MainWindow.draw(arrow);
	//          lane, timing, revolutionary map editor btw
	arrows.insert({ 0.5f , ArrowDirection::LEFT });
	arrows.insert({ 1.0f, ArrowDirection::UP });
	arrows.insert({ 1.5f, ArrowDirection::DOWN });
	arrows.insert({ 2.0f, ArrowDirection::RIGHT });
	arrows.insert({ 2.5f, ArrowDirection::LEFT });
	arrows.insert({ 3.0f, ArrowDirection::UP });
	arrows.insert({ 3.5f, ArrowDirection::UP });
	arrows.insert({ 3.75f, ArrowDirection::DOWN });
	arrows.insert({ 4.0f, ArrowDirection::RIGHT });
	arrows.insert({ 4.25f, ArrowDirection::LEFT });
	arrows.insert({ 4.5f, ArrowDirection::UP });
	arrows.insert({ 4.75f, ArrowDirection::DOWN });


}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(arrowSprite, states);
}

std::pair<float, ArrowDirection::dirs> Arrow::GetNextAction()
{
	sf::Time elapsed1 = GameTimer.getElapsedTime();
	// 1 seconde = 100 milliseconds = 1000 microseconds
		//std::cout << elapsed1.asSeconds() << std::endl;
	std::pair<float, ArrowDirection::dirs> nextAction;
	float previous = 0.0f;
	for (auto const& [key, val] : arrows)
	{
		if (key > previous) {
			nextAction = { key, val };
			previous = key;
			break;
		}
	}

	return nextAction;
}