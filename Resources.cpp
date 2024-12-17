#include "Resources.h"
Resources* Resources::instance = nullptr;

Resources::Resources() 
{
}

Resources::~Resources()    
{
}

void Resources::Load()
{
    sf::Texture* textureToLoad;
    
    textureToLoad.loadFromFile("resources/gamesprites/arrowDown.png");
    textures.insert({ Resources::DownArrow, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/arrowLeft.png");
    textures.insert({ Resources::LeftArrow, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/arrowRight.png");
    textures.insert({ Resources::RightArrow, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/arrowUp.png");
    textures.insert({ Resources::UpArrow, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/ArrowDownKD.png");
    textures.insert({ Resources::DownArrowPressed, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/ArrowLeftKD.png");
    textures.insert({ Resources::LeftArrowPressed, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/ArrowRightKD.png");
    textures.insert({ Resources::RightArrowPressed, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/arrowUpKD.png");
    textures.insert({ Resources::UpArrowPressed, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/ArrowDownD.png");
    textures.insert({ Resources::DownArrowController, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/ArrowLeftD.png");
    textures.insert({ Resources::LeftArrowController, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/ArrowRightD.png");
    textures.insert({ Resources::RightArrowController, &textureToLoad });
    textureToLoad.loadFromFile("resources/gamesprites/ArrowUpD.png");
    textures.insert({ Resources::UpArrowController, &textureToLoad });
}

const sf::Texture* Resources::GetTexture(Resources::Asset assetToGet)
{
    for (auto const& [key, val] : textures)
    {
        if (key == assetToGet) {
            return &val;
        }
    }
	return nullptr;
}

void Resources::MakeTexturesSmooth()
{
    for (auto& [key, texture] : textures)
    {
        texture.setSmooth(true);
    }
}

void Resources::Load(std::string aPath)
{
    sf::Texture* t = new sf::Texture();
    *t->loadFromFile(aPath);

}

Resources* Resources::GetInstance()
{
    if (instance == nullptr) {
        instance = new Resources();
    }
	return instance;
}
