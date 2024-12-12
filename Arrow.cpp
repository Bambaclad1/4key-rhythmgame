#include "Arrow.h"

Arrow::Arrow(ArrowDirection aDirection) : speed(500.0f), direction(aDirection)  // Use member initializer to set speed.
{
	std::cout << "Arrow loaded!\n";
	InitSprite();
	switch (aDirection)
	{
	case ArrowDirection::LEFT:
		arrowSprite.setTexture(arrowLeftFalling);
		arrowSprite.setPosition(450, 700);
		break;
	case ArrowDirection::UP:
		arrowSprite.setTexture(arrowUpFalling);
		arrowSprite.setPosition(450, 700);
		break;
	case ArrowDirection::DOWN:
		arrowSprite.setTexture(arrowDownFalling);
		arrowSprite.setPosition(450, 700);
		break;
	case ArrowDirection::RIGHT:
		arrowSprite.setTexture(arrowRightFalling);
		arrowSprite.setPosition(450, 700);
		break;
	default:
		break;
	}
	GameTimer.restart();
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
	arrowLeftFalling.setSmooth(true);
	arrowUpFalling.setSmooth(true); 
	arrowDownFalling.setSmooth(true);
	arrowRightFalling.setSmooth(true);

	arrowSprite.setScale(0.5f, 0.5f);
	/*arrowLeft.setPosition(450, 700);
	arrowDown.setPosition(600, 700);
	arrowUp.setPosition(750, 700);
	arrowRight.setPosition(900, 700);*/

	

}

void Arrow::Update(sf::RenderWindow& MainWindow, float deltaTime)
{

	arrowSprite.move(0, speed * deltaTime);
	float mss = GameTimer.getElapsedTime().asSeconds();
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
