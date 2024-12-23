#include "Arrow.h"

Arrow::Arrow() : speed(500.0f)  // Use member initializer to set speed.
{
	nerdfont.loadFromFile("resources/fonts/0xProtoNerdFont-Regular.ttf");
	timerDebug.setFont(nerdfont);
	timerDebug.setPosition(0, 50);
	timerDebug.setFillColor(sf::Color::Black);
	timerDebug.setCharacterSize(32);

	std::cout << "Arrow loaded!" << std::endl;
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

void Arrow::Update(sf::RenderWindow& MainWindow, float deltaTime) // ik heb hiervoor GPT gebruikt!
{
	// Move the arrow sprite downwards
	for (size_t i = 0; i < fallingarrows.size(); i++)
	{
		fallingarrows[i].move(0, speed * deltaTime);
	}

	float mss = GameTimer.getElapsedTime().asSeconds();
	std::string mssString = std::to_string(mss);
	timerDebug.setString(mssString);

	// Process the next arrow in the queue if time has passed its spawn time
	while (!arrows.empty() && mss >= arrows.begin()->first) {
		float spawnTime = arrows.begin()->first;
		auto direction = arrows.begin()->second;

		// Check if this spawn time has already been processed
		if (spawnedArrows.find(spawnTime) == spawnedArrows.end()) {
			// Mark this spawn time as processed
			spawnedArrows.insert(spawnTime);

			sf::Sprite arrowComingToVector;
			arrowComingToVector.setScale(0.5f, 0.5f);

			// Process the direction and spawn the arrow
			switch (direction) {
			case ArrowDirection::LEFT:
				arrowComingToVector.setTexture(arrowLeftFalling);
				arrowComingToVector.setPosition(450, -250);
				fallingarrows.push_back(arrowComingToVector);
				break;
			case ArrowDirection::UP:
				arrowComingToVector.setTexture(arrowUpFalling);
				arrowComingToVector.setPosition(750, -250);
				fallingarrows.push_back(arrowComingToVector);
				break;
			case ArrowDirection::DOWN:
				arrowComingToVector.setTexture(arrowDownFalling);
				arrowComingToVector.setPosition(600, -250);
				fallingarrows.push_back(arrowComingToVector);
				break;
			case ArrowDirection::RIGHT:
				arrowComingToVector.setTexture(arrowRightFalling);
				arrowComingToVector.setPosition(900, -250);
				fallingarrows.push_back(arrowComingToVector);
				break;
			default:
				std::cout << "unknown direction!" << std::endl;
			}
		}

		// Remove the processed arrow to avoid reprocessing it
		arrows.erase(arrows.begin());
	}

	// Draw the current arrow
	//MainWindow.draw(arrowSprite);
}

void Arrow::testsong(sf::RenderWindow& MainWindow)
{
	//MainWindow.draw(arrow);
	//          lane, timing, revolutionary map editor btw
	arrows.insert({ 0.5f , ArrowDirection::LEFT });
	arrows.insert({ 0.500001f , ArrowDirection::RIGHT });
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

void Arrow::RemoveFirstArrowInMap()
{
	if (!arrows.empty()) {
		arrows.erase(arrows.begin());
		std::cout << "Arrow Removed!\n";
	}
	else {
		std::cout << "Map is empty, no arrow to remove.\n";
	}

}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(timerDebug);
	for (int i = 0; i < fallingarrows.size(); i++)
	{
		//target.draw(fallingarrows[i]);
	}
}


std::pair<float, ArrowDirection> Arrow::GetNextAction()
{
	sf::Time elapsed1 = GameTimer.getElapsedTime();
	// 1 seconde = 100 milliseconds = 1000 microseconds
		//std::cout << elapsed1.asSeconds() << std::endl;
	std::pair<float, ArrowDirection> nextAction;
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