#pragma once

#include <sfml/Graphics/RenderTarget.hpp>
#include <sfml/System/Vector2.hpp>

struct IEntity
{
	virtual ~IEntity() = default;

	virtual sf::Vector2f getPosition() const = 0;
	virtual void setPosition(const sf::Vector2f &pos) = 0;

	virtual void tick(float seconds) = 0;
	virtual void render(sf::RenderTarget &target) const = 0;
};