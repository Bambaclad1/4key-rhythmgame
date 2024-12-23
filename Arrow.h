#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include "ArrowDirection.h"
#include <iostream>
#include <set>
/*
					Idea for deploying well managed arrows!
					---------------------------------------
	* Make a std::map where we will store the following:
	* int, float. Int will be explaining which lane we will launch the arrows at.
	* Example, lane 1, arr left, lane 2, arr up. etc etc
	* Float will explain the timing, so for example, 0.5f will be the timing the
	* arrow will fall down. It should be synchronized with the song in SOME way,
	* so that is why we will use a int called BPM for that. That will be declared in
	* the Maps class, and not in here, otherwise its a lot.
	* We should make a algorithm that automatically knows which lane goes where,
	* by just some calculations in the code and switching if it counts or not.
	*
	* Anyway, what more? Hm, probably some movement with deltatime. Thats it!
	*/
class Arrow : public sf::Drawable, public sf::Transformable {
public:
	Arrow(); 
	~Arrow();
	void InitSprite();
	void Update(sf::RenderWindow& MainWindow, float deltaTime);
	void testsong(sf::RenderWindow& MainWindow);
	void RemoveFirstArrowInMap();
	virtual void draw(sf::RenderTarget& MainWindow, sf::RenderStates states) const;

	std::vector<sf::Sprite> GetVectorArrows() {
		return fallingarrows;
	}
	std::map<float, ArrowDirection> arrows;  // int = lane, float = timing, bool is has dropped. made public btw

private:
	sf::Clock GameTimer;

	std::map<float, Arrow*> arro0ws;  // int = lane, float = timing
	std::set<float> spawnedArrows;  



	int BPM = 0;
	float speed = 0;

	float elapsedTime = 0.0f;

	sf::Texture arrowLeftFalling;
	sf::Texture arrowUpFalling;
	sf::Texture arrowDownFalling;
	sf::Texture arrowRightFalling;
	
	sf::Text timerDebug; // shows the timer of the std::map maps in the game
	sf::Font nerdfont;

	std::vector<sf::Sprite> fallingarrows; // Vector of arrows that are falling
	sf::Sprite arrowSprite;

	bool DebugRanOnce = true;

	sf::RenderWindow test;
	ArrowDirection direction; 

	std::pair<float, ArrowDirection> GetNextAction();


};
