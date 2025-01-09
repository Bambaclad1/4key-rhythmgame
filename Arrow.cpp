#include "Arrow.h"

Arrow::Arrow()
{
	nerdfont.loadFromFile("resources/fonts/0xProtoNerdFont-Regular.ttf");
	timerDebug.setFont(nerdfont);
	timerDebug.setPosition(0, 50);
	timerDebug.setFillColor(sf::Color::Black);
	timerDebug.setCharacterSize(32);

	PlayingMapInfo.setFont(nerdfont);
	PlayingMapInfo.setPosition(1100, 0);
	PlayingMapInfo.setFillColor(sf::Color::Black);
	PlayingMapInfo.setCharacterSize(16);

	PrintMap.setFont(nerdfont);
	PrintMap.setPosition(300, 50);
	PrintMap.setFillColor(sf::Color::Black);
	PrintMap.setCharacterSize(9);



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

	arrowLeftFalling.setSmooth(true);
	arrowUpFalling.setSmooth(true);
	arrowDownFalling.setSmooth(true);
	arrowRightFalling.setSmooth(true);
	arrowSprite.setPosition(450, 100);
	arrowSprite.setTexture(arrowLeftFalling);
	arrowSprite.setScale(0.5f, 0.5f);

}

void Arrow::Update(sf::RenderWindow& MainWindow, float deltaTime)
{
	if (FlagOnce) {
		GameTimer.restart();
		FlagOnce = false;
	}
	float mss = GameTimer.getElapsedTime().asSeconds();
	std::string mssString = std::to_string(mss);
	timerDebug.setString(mssString);

	// Spawn new arrows based on timing
	while (!arrows.empty() && mss >= arrows.begin()->first) {
		float spawnTime = arrows.begin()->first;
		auto direction = arrows.begin()->second;

		if (spawnedArrows.find(spawnTime) == spawnedArrows.end()) {
			spawnedArrows.insert(spawnTime);

			sf::Sprite arrow;
			arrow.setScale(0.5f, 0.5f);

			switch (direction) {
			case ArrowDirection::LEFT:
				arrow.setTexture(arrowLeftFalling);
				arrow.setPosition(450, -250);
				break;
			case ArrowDirection::UP:
				arrow.setTexture(arrowUpFalling);
				arrow.setPosition(750, -250);
				break;
			case ArrowDirection::DOWN:
				arrow.setTexture(arrowDownFalling);
				arrow.setPosition(600, -250);
				break;
			case ArrowDirection::RIGHT:
				arrow.setTexture(arrowRightFalling);
				arrow.setPosition(900, -250);
				break;
			}
			fallingarrows.push_back(arrow);
			std::cout << "Spawned arrow at time: " << spawnTime << "\n";
		}

		arrows.erase(arrows.begin());
	}
}


void Arrow::testsong(sf::RenderWindow& MainWindow, float bpm, float deltaTime)
{
	if (runOnce) {
		if (!CurrentLoadedSong.openFromFile("resources/music/Seiryu - AO Infinity.wav"))
			std::cout << "Error! Unable to load song! Check resources/music if the file is there!" << std::endl;

		std::cout << "Init Map Data Start" << std::endl;
		std::string MapName = "AO-Infinity";
		std::string SongArtist = "Seiryu";
		std::string MapArtist = "bambaisbanned";
		std::string MapDifficulty = "Hard";
		std::string SongInfo = "Song: " + SongArtist + " - " + MapName + "\n" + "Mapper: " + MapArtist + "\n" + "Difficulty: " + MapDifficulty;
		float secondsPerBeat = 60.0f / bpm;
		float arrowTravelDistance = 700.0f; // Distance the arrow should travel in pixels
		float speed = arrowTravelDistance / secondsPerBeat; // arrowTravelDistance is how far an arrow should fall in one beat
		PlayingMapInfo.setString(SongInfo);

		CurrentLoadedSong.play();

		runOnce = false;
		std::cout << "Map " << SongArtist << " - " << MapName << " Difficulty " << MapDifficulty << " loaded!" << std::endl;
	}
	MainWindow.draw(PlayingMapInfo);
	
	//				timing,                 lane		 revolutionary map editor btw, goodluck
	arrows.insert({ 0.8f, ArrowDirection::LEFT });
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
	arrows.insert({ 50.75f, ArrowDirection::DOWN }); // temporaily fixes issue #4 on github where the game will crash after the last arrow is spawned

	// Update arrow positions ( move down ) 
	for (size_t i = 0; i < fallingarrows.size(); i++) {
		fallingarrows[i].move(0, speed * deltaTime);
	}

}

void Arrow::ryanmap(sf::RenderWindow& MainWindow, float bpm, float deltaTime)
{
	if (runOnce) {
		if (!CurrentLoadedSong.openFromFile("resources/music/.wav"))
			std::cout << "Error! Unable to load song! Check resources/music if the file is there!" << std::endl;

		std::cout << "Init Map Data Start" << std::endl;
		std::string MapName = "AO-Infinity";
		std::string SongArtist = "Seiryu";
		std::string MapArtist = "bambaisbanned";
		std::string MapDifficulty = "Hard";
		std::string SongInfo = "Song: " + SongArtist + " - " + MapName + "\n" + "Mapper: " + MapArtist + "\n" + "Difficulty: " + MapDifficulty;
		float secondsPerBeat = 60.0f / bpm;
		float arrowTravelDistance = 700.0f; // Distance the arrow should travel in pixels
		float speed = arrowTravelDistance / secondsPerBeat; // arrowTravelDistance is how far an arrow should fall in one beat
		PlayingMapInfo.setString(SongInfo);

		CurrentLoadedSong.play();

		runOnce = false;
		std::cout << "Map " << SongArtist << " - " << MapName << " Difficulty " << MapDifficulty << " loaded!" << std::endl;
	}
	MainWindow.draw(PlayingMapInfo);

	//				timing,                 lane		 revolutionary map editor btw, goodluck
	arrows.insert({ 0.8f, ArrowDirection::LEFT });
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
	arrows.insert({ 50.75f, ArrowDirection::DOWN }); // temporaily fixes issue #4 on github where the game will crash after the last arrow is spawned

	// Update arrow positions ( move down ) 
	for (size_t i = 0; i < fallingarrows.size(); i++) {
		fallingarrows[i].move(0, speed * deltaTime);
	}

}

void Arrow::RemoveFirstArrowInMap()
{

	if (!fallingarrows.empty()) {
		fallingarrows.erase(fallingarrows.begin());
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
		target.draw(fallingarrows[i]);
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