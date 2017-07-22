#include "texmanager.hpp"

#include <utility>
#include <cstdint>

TexManager::TexManager()
{
	sf::Image image;
	image.create(1, 1, { 255, 255, 255 });
	DefaultTexture.loadFromImage(image);
}

const sf::Texture &TexManager::get(const std::string &name)
{
	auto it = Cache.find(name);
	if(it == Cache.end()) //not cached yet, load from file
	{
		sf::Texture texture;
		if(!texture.loadFromFile("data/" + name + ".png"))
			return DefaultTexture;

		auto ret = Cache.insert({name, std::move(texture)});

		return ret.first->second;
	}

	return it->second;

}
