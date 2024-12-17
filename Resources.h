#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Resources
{

public:
	enum Asset {
		DownArrow,
		LeftArrow,
		RightArrow,
		UpArrow,
		DownArrowPressed,
		LeftArrowPressed,
		RightArrowPressed,
		UpArrowPressed,
		DownArrowController,
		LeftArrowController,
		RightArrowController,
		UpArrowController
	};

public:
	static Resources* GetInstance();
	const sf::Texture* GetTexture(Resources::Asset assetToGet);
	void MakeTexturesSmooth();
	void Load(std::string aPath);

private:
	Resources();
	~Resources();
	void Load();
	std::map < Resources::Asset, sf::Texture*> textures;
	static Resources* instance;


	

};

