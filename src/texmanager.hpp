#pragma once
#include <vector>
#include <string>
#include <map>

#include <sfml/Graphics/Texture.hpp>

class TexManager
{
public:
	TexManager();

	//loads texture <name>.png if not already in cache. Returns a default texture when not found.
	const sf::Texture &get(const std::string &name);

private:
	std::map<std::string, sf::Texture> Cache;

	sf::Texture DefaultTexture;
};