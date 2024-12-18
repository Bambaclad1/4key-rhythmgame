#include "Resources.h"

Resources::Resources() 
{

}

Resources::~Resources()    
{
}

void Resources::Load()
{
    
    sf::Texture textureToLoad;
    textureToLoad.loadFromFile("resources/gamesprites/arrowDown.png");
    textures.insert({ Resources::DownArrow, textureToLoad });



}

const sf::Texture* Resources::GetTexture(Resources::Asset assetToGet) const
{
    for (auto const& [key, val] : textures)
    {
        if (key == assetToGet) {
            return &val;
        }
    }
	return nullptr;
}

Resources* Resources::GetInstance()
{
    if (instance == nullptr) {
        instance = new Resources();
    }
	return instance;
}
