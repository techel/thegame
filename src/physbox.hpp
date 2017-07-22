#pragma once
#include <array>
#include <functional>

#include "physics.hpp"

#include <sfml/System/Vector2.hpp>

//
// creates a physical box with a sensor on each side (left, right, top, bottom)
//

class Box : private ICollisionListener
{
public:
    enum class Direction : size_t { Left = 0, Right, Bottom, Top };
    enum class Collision { Touch, Untouch };
    using Listener = std::function<void(Box&, IEntity&, Direction, Collision)>;

    struct Predefinitions
    {
        b2BodyDef Body;
        b2FixtureDef MainFix, LeftSensor, RightSensor, TopSensor, BottomSensor;
    };

    Box(Physics &ph, const sf::Vector2f &size, float sensorsize, const Predefinitions &pre);

    b2Body &body() { return *MyBody; }
    const b2Body &body() const { return *MyBody; }

    int getNumTouches(Direction d) const;

    void observeCollision(Listener l);

private:
    BodyHolder MyBody;
    std::array<b2Fixture*, 4> SensorFixtures;
    size_t fixToIndex(const b2Fixture *f);

    Ticket CollTicket;
    Listener CollListener;

    std::array<int, 4> NumTouches;

    void beginContact(b2Contact &c, size_t index, IEntity &entityB) override;
    void endContact(b2Contact &c, size_t index, IEntity &entityB) override;

};
