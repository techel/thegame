#pragma once

#include <memory>
#include <sfml/Graphics/RectangleShape.hpp>

#include "entity.hpp"
#include "physics.hpp"

class Map;
class App;

class Platform : public IEntity
{
public:
    Platform(Map &map, App &app, float width);

    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f &pos) override;

    void tick(float seconds) override;
    void render(sf::RenderTarget &target) const override;

private:
	sf::RectangleShape Sprite;
    BodyHolder Body;
};