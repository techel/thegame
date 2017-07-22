#pragma once

#include <sfml/Graphics/RectangleShape.hpp>

#include "entity.hpp"
#include "animation.hpp"

class Map;
class App;

class Explosion : public IEntity
{
public:
    Explosion(Map &map, App &app);

    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f &pos) override;

    void tick(float seconds) override;
    void render(sf::RenderTarget & target) const override;

private:
    sf::RectangleShape Shape;
    Animation Anim;
};