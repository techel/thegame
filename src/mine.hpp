#pragma once

#include <sfml/Graphics/RectangleShape.hpp>

#include "entity.hpp"
#include "animation.hpp"
#include "physbox.hpp"

class Map;
class App;
class Platform;

class Mine : public IEntity
{
public:
    Mine(Map &map, App &app);

    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f &pos) override;

    void toss(const sf::Vector2f &dir);

    void tick(float seconds) override;
    void render(sf::RenderTarget & target) const override;

private:
    App *MyApp;
    Map *MyMap;

    sf::RectangleShape Shape;
    Animation Anim;

    std::unique_ptr<Box> Body;

    enum class State { Toss, Stick, None } CurrentState = State::None;

    Platform *DestPlatform = nullptr;
    Ticket PlatformTicket;
    float StickTime;
};