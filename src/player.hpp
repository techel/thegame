#pragma once

#include <sfml/Graphics.hpp>
#include <functional>

#include "entity.hpp"
#include "app.hpp"
#include "map.hpp"

class Player : public IEntity
{
public:
	Player(Map &map, App &app);

	sf::Vector2f getPosition() const override;
	void setPosition(const sf::Vector2f &pos) override;

	void tick(float seconds) override;
	void render(sf::RenderTarget & target) const override;

private:
	sf::RectangleShape Sprite;
    
};
