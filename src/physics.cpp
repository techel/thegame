#pragma once
#include "physics.hpp"

#include <iterator>


Physics::Physics() : TheWorld({0.0f, -35.0f})
{
    TheWorld.SetContactListener(this);
}
void Physics::BeginContact(b2Contact *contact)
{
    void *fixUserDataA = contact->GetFixtureA()->GetUserData();
    void *fixUserDataB = contact->GetFixtureB()->GetUserData();
    void *bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void *bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if(fixUserDataA && bodyUserDataB)
        static_cast<ICollisionListener*>(fixUserDataA)->beginContact(*contact, 0, *static_cast<IEntity*>(bodyUserDataB));
    if(fixUserDataB && bodyUserDataA)
        static_cast<ICollisionListener*>(fixUserDataB)->beginContact(*contact, 1, *static_cast<IEntity*>(bodyUserDataA));
}
void Physics::EndContact(b2Contact *contact)
{
    void *fixUserDataA = contact->GetFixtureA()->GetUserData();
    void *fixUserDataB = contact->GetFixtureB()->GetUserData();
    void *bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void *bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if(fixUserDataA && bodyUserDataB)
        static_cast<ICollisionListener*>(fixUserDataA)->endContact(*contact, 0, *static_cast<IEntity*>(bodyUserDataB));
    if(fixUserDataB && bodyUserDataA)
        static_cast<ICollisionListener*>(fixUserDataB)->endContact(*contact, 1, *static_cast<IEntity*>(bodyUserDataA));
}
auto Physics::observeCollisions(ICollisionListener &l) -> CollisionTicket
{
    CollisionListeners.push_back(&l);
    auto it = std::prev(CollisionListeners.end());
    return CollisionTicket([this, it]()
    {
        CollisionListeners.erase(it);
    });
}
void Physics::tick(float seconds)
{
    TheWorld.Step(seconds, 3, 3);
}

