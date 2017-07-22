#include "player.hpp"

#include "texmanager.hpp"

Player::Player(Map &map, App &app)
{
	Sprite.setTexture(&app.textures().get("player"));
	Sprite.setSize({ 10.0f, 10.0f });
	Sprite.setPosition({5.0f, 0.3f});
}

sf::Vector2f Player::getPosition() const
{
	return Sprite.getPosition();
}

void Player::setPosition(const sf::Vector2f &pos)
{
	Sprite.setPosition(pos);
}

void Player::tick(float seconds)
{
}

void Player::render(sf::RenderTarget &target) const
{
	target.draw(Sprite);
}
