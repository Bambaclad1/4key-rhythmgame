#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Drawer.h"  
class Drawer;
class ScoreSystem
{
public:
	ScoreSystem();
	void GetArrowPositions();
private:
	Drawer* drawer;

};

