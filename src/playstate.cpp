#include "playstate.hpp"

#include "soundmanager.hpp"

#include "player.hpp"
#include "platform.hpp"
#include "explosion.hpp"

PlayState::PlayState(App &app) : TheMap(app)
{
	app.sound().playMusic("test");

	auto &player1 = TheMap.addEntity<Player>(TheMap, app);
	player1.setPosition({ 0.0f, 0.0f });

    auto &player2 = TheMap.addEntity<Player>(TheMap, app);
    player2.setPosition({ 2.0f, 0.0f });

    TheMap.camera().follow({ &player1, &player2 });

    TheMap.player1().setPlayer(player1, PlayerController::InputMode::Player1);
    TheMap.player2().setPlayer(player2, PlayerController::InputMode::Player2);

    auto &plat = TheMap.addEntity<Platform>(TheMap, app, 20.0f);
    plat.setPosition({ -2.0f, 20.0f });

    auto &plat2 = TheMap.addEntity<Platform>(TheMap, app, 40.0f);
    plat2.setPosition({ 3.0f, 30.0f });
}

void PlayState::tick(float seconds)
{
	TheMap.tick(seconds);
}

void PlayState::render(sf::RenderTarget &target) const
{
	TheMap.render(target);
}
