#include "playstate.hpp"

#include "soundmanager.hpp"

#include "player.hpp"
#include "platform.hpp"
#include "explosion.hpp"

Ticket t;

PlayState::PlayState(App &app) : TheMap(app)
{
	app.sound().playMusic("test");

	auto &player = TheMap.addEntity<Player>(TheMap, app);
	player.setPosition({ 0.0f, 0.0f });

    TheMap.player1().setPlayer(player, PlayerController::InputMode::Player1);

	t = TheMap.camera().follow(&player);

    auto &plat = TheMap.addEntity<Platform>(TheMap, app, 20.0f);
    plat.setPosition({ -2.0f, 20.0f });

    auto &plat2 = TheMap.addEntity<Platform>(TheMap, app, 40.0f);
    plat2.setPosition({ 3.0f, 30.0f });

    auto &expl = TheMap.addEntity<Explosion>(TheMap, app);
    expl.setPosition({ 2.0f, 2.0f });
}

void PlayState::tick(float seconds)
{
	TheMap.tick(seconds);
}

void PlayState::render(sf::RenderTarget &target) const
{
	TheMap.render(target);
}
