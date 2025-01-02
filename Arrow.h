#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "ArrowDirection.h"
#include <iostream>
#include <set>
class Arrow : public sf::Drawable, public sf::Transformable {
public:
	Arrow(); 
	~Arrow();
	void InitSprite();
	void Update(sf::RenderWindow& MainWindow, float deltaTime);
	void testsong(sf::RenderWindow& MainWindow, float bpm, float deltaTime);
	void RemoveFirstArrowInMap();
	virtual void draw(sf::RenderTarget& MainWindow, sf::RenderStates states) const;

	std::vector<sf::Sprite> GetVectorArrows() {
		return fallingarrows;
	}
	sf::Clock GameTimer;

private:
	//sf::Time elapsed = GameTimer.restart();
//	float deltaTimeArrow = elapsed.asSeconds();

	std::map<float, ArrowDirection> arrows;  // int = lane, float = timing, bool is has dropped. 
	std::map<float, Arrow*> arro0ws;  // int = lane, float = timing
	std::set<float> spawnedArrows;  

	sf::Music CurrentLoadedSong;
	float speed = 600;
	float bpm;
	float distance;
	float windowHeight;

	float elapsedTime = 0.0f;

	sf::Texture arrowLeftFalling;
	sf::Texture arrowUpFalling;
	sf::Texture arrowDownFalling;
	sf::Texture arrowRightFalling;
	
	sf::Text timerDebug; // shows the timer of the std::map maps in the game
	sf::Text PlayingMapInfo; // shows the map info/name
	sf::Text PrintMap; // shows coordinates ingame
	sf::Font nerdfont;

	std::vector<sf::Sprite> fallingarrows; // Vector of arrows that are falling
	sf::Sprite arrowSprite;

	bool DebugRanOnce = true;
	bool FlagOnce = true;

	sf::RenderWindow test;
	ArrowDirection direction; 

	std::pair<float, ArrowDirection> GetNextAction();

	bool runOnce = true;


};
