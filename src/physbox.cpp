#include "physbox.hpp"

#include <algorithm>

Box::Box(Physics &ph, const sf::Vector2f &size, float sensorsize, const Predefinitions &pre)
{
    MyBody.reset(ph.world().CreateBody(&pre.Body));

    b2FixtureDef fix;
    b2PolygonShape shape;
    sf::Vector2f hsize = size / 2.0f;
    float hsenssize = sensorsize / 2.0f;

    MyBody->CreateFixture(&pre.MainFix); //main fixture

    shape.SetAsBox(hsenssize, hsize.y - sensorsize, { -hsenssize, hsize.y }, 0);
    fix = pre.LeftSensor;
    fix.shape = &shape;
    fix.isSensor = true;
    fix.userData = static_cast<ICollisionListener*>(this);
    SensorFixtures[0] = MyBody->CreateFixture(&fix); //left sensor fixture

    shape.SetAsBox(hsenssize, hsize.y - sensorsize, { size.x + hsenssize, hsize.y }, 0);
    fix = pre.RightSensor;
    fix.shape = &shape;
    fix.isSensor = true;
    fix.userData = static_cast<ICollisionListener*>(this);
    SensorFixtures[1] = MyBody->CreateFixture(&fix); //right sensor fixture

    shape.SetAsBox(hsize.x - sensorsize, hsenssize, { hsize.x, size.y + hsenssize }, 0);
    fix = pre.TopSensor;
    fix.shape = &shape;
    fix.isSensor = true;
    fix.userData = static_cast<ICollisionListener*>(this);
    SensorFixtures[2] = MyBody->CreateFixture(&fix); //top sensor fixture

    shape.SetAsBox(hsize.x - sensorsize, hsenssize, { hsize.x, -hsenssize }, 0);
    fix = pre.BottomSensor;
    fix.shape = &shape;
    fix.isSensor = true;
    fix.userData = static_cast<ICollisionListener*>(this);
    SensorFixtures[3] = MyBody->CreateFixture(&fix); //bottom sensor fixture

    CollTicket = ph.observeCollisions(*this);

    std::fill_n(NumTouches.begin(), 4, 0);
}
size_t Box::fixToIndex(const b2Fixture *f)
{
    for(size_t i = 0; i < 4; ++i)
    {
        if(SensorFixtures[i] == f)
            return i;
    }
    return 0xFF;
}
void Box::beginContact(b2Contact &c, size_t index, IEntity &entityB)
{
    auto fixidx = fixToIndex(index == 0 ? c.GetFixtureA() : c.GetFixtureB());
    if(fixidx != 0xFF)
    {
        if(CollListener)
            CollListener(*this, entityB, static_cast<Direction>(fixidx), Collision::Touch);
        NumTouches[fixidx]++;
    }
}
void Box::endContact(b2Contact &c, size_t index, IEntity &entityB)
{
    auto fixidx = fixToIndex(index == 0 ? c.GetFixtureA() : c.GetFixtureB());
    if(fixidx != 0xFF)
    {
        if(CollListener)
            CollListener(*this, entityB, static_cast<Direction>(fixidx), Collision::Untouch);
        NumTouches[fixidx]--;
    }
}
int Box::getNumTouches(Direction d) const
{
    size_t fixidx = static_cast<size_t>(d);
    return NumTouches[fixidx];
}
void Box::observeCollision(Listener l)
{
    CollListener = l;
}
