#pragma once
#include <SFML/Graphics.hpp>
#include "ArrowDirection.h"
#include "ControllerUp.h"
#include "ControllerDown.h"
#include "ControllerLeft.h"
#include "ControllerRight.h"

class Controller : public sf::Drawable, public sf::Transformable
{
public:
	Controller(ArrowDirection aDirection);
	~Controller();
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	ArrowDirection direction;
};

