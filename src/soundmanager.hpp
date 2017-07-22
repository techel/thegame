#pragma once

#include <map>
#include <string>
#include <array>
#include <map>
#include <cstddef>

#include <sfml/Audio/Sound.hpp>
#include <sfml/Audio/SoundBuffer.hpp>
#include <sfml/Audio/Music.hpp>

class SoundManager
{
public:
	SoundManager() = default;

	//plays <name>.ogg from data folder
	void playMusic(const std::string &name);

	//loads <name>.ogg if not already in cache and plays it
	void playSound(const std::string &name);

private:
	sf::Music Music;

	static constexpr size_t NumSfxSlots = 8;
	std::array<sf::Sound, NumSfxSlots> SfxSlots;

	std::map<std::string, sf::SoundBuffer> SfxCache;
};