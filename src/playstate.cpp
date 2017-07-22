#include "playstate.hpp"

#include "soundmanager.hpp"

#include "player.hpp"
#include "platform.hpp"
#include "explosion.hpp"

PlayState::PlayState(App &app) : TheMap(app)
{
	app.sound().playMusic("test");

	auto &player = TheMap.addEntity<Player>(TheMap, app);
	player.setPosition({ 0.0f, 0.0f });

	TheMap.player1().setPlayer(player, PlayerController::InputMode::Player1);
	TheMap.camera().follow({ &player });
	
	auto &expl = TheMap.addEntity<Explosion>(TheMap, app);
	expl.setPosition({ 2.0f, 2.0f });

	TheMap.generate(app);
}

void PlayState::tick(float seconds)
{
	TheMap.tick(seconds);
}

void PlayState::render(sf::RenderTarget &target) const
{
	TheMap.render(target);
}
