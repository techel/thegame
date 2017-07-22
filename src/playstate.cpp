#include "playstate.hpp"

#include "soundmanager.hpp"
#include "player.hpp"

PlayState::PlayState(App &app)
{
	app.sound().playMusic("test");

	auto &player = TheMap.addEntity<Player>(TheMap, app);
	player.setPosition({ 0.5f, 0.5f });
}

void PlayState::tick(float seconds)
{
	TheMap.tick(seconds);
}

void PlayState::render(sf::RenderTarget &target) const
{
	TheMap.render(target);
}
