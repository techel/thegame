#include "playstate.hpp"

#include "soundmanager.hpp"
#include "player.hpp"

Ticket t;

PlayState::PlayState(App &app)
{
	app.sound().playMusic("test");

	auto &player = TheMap.addEntity<Player>(TheMap, app);
	player.setPosition({ 0.5f, 0.5f });

	t = TheMap.camera().follow(&player);
}

void PlayState::tick(float seconds)
{
	TheMap.tick(seconds);
}

void PlayState::render(sf::RenderTarget &target) const
{
	TheMap.render(target);
}
