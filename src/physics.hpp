#pragma once
#include <memory>
#include <list>
#include "entity.hpp"

#include <box2d/Box2D.h>

#include "ticket.hpp"
#include "nonmovable.hpp"

//
// box2d object wrapper
//

struct BodyDestroyer
{
    void operator()(b2Body *b)
    {
        b->GetWorld()->DestroyBody(b);
    }
};

typedef std::unique_ptr<b2Body, BodyDestroyer> BodyHolder;

struct FixtureDestroyer
{
    void operator()(b2Fixture *f)
    {
        f->GetBody()->DestroyFixture(f);
    }
};

typedef std::unique_ptr<b2Body, FixtureDestroyer> FixtureHolder;

//
// fixture filters
//

namespace Filter
{
    using FilterType = decltype(b2Filter::categoryBits);
    constexpr FilterType Player = 1;
    constexpr FilterType Wall = 2;
    constexpr FilterType Interactable = 4;
    constexpr FilterType All = 0xFF;
}

//
// collision listener
//
// A fixture A may hold a pointer to such collision listener in it's user-data. The owning body of
// fixture B has to hold a pointer to the corresponding entity.
//

struct ICollisionListener
{
    virtual ~ICollisionListener() = default;
    virtual void beginContact(b2Contact &c, size_t index, IEntity &entityB) = 0;
    virtual void endContact(b2Contact &c, size_t index, IEntity &entityB) = 0;
};

//
// physics
//

class Physics : private b2ContactListener, nonCopyable, nonMovable
{
public:
    Physics();

    b2World &world() { return TheWorld; }
    const b2World &world() const { return TheWorld; }

    typedef Ticket CollisionTicket;
    CollisionTicket observeCollisions(ICollisionListener &l);

    void tick(float seconds);

private:
	b2World TheWorld;

    void BeginContact(b2Contact *contact) override;
    void EndContact(b2Contact *contact) override;

    std::list<ICollisionListener*> CollisionListeners;
};