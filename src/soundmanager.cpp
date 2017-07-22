#include "soundmanager.hpp"

#include <utility>

void SoundManager::playMusic(const std::string &name)
{
	Music.stop();
	Music.openFromFile("data/" + name + ".ogg");
	Music.play();
}

void SoundManager::playSound(const std::string & name)
{
	auto it = SfxCache.find(name);
	if(it == SfxCache.end())
	{
		sf::SoundBuffer buffer;
		buffer.loadFromFile("data/" + name + ".ogg");

		auto res = SfxCache.insert({ name, std::move(buffer) });
		it = res.first;
	}
	
	for(auto &slot : SfxSlots)
	{
		if(slot.getStatus() != slot.Playing)
		{
			slot.setBuffer(it->second);
			slot.play();
			break;
		}
	}
}
