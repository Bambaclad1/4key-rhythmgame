#pragma once
#include <SFML/Graphics.hpp>
#include "Drawer.h"
#include <map>
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
	*/
class Arrow
{
public:
	Arrow(); // const
	~Arrow(); // destr
	void InitSprite();
	void testsong();
private:
	std::map<int, float> people; // int = lane, float = timing
	int BPM = 0;

	sf::Texture arrowLeftFalling;
	sf::Texture arrowUpFalling;
	sf::Texture arrowDownFalling;
	sf::Texture arrowRightFalling;

	sf::Sprite arrow;
};
