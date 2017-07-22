#include "entity.hpp"

Ticket IEntity::observeDestruction(std::function<void()> listener)
{
    DestructionListener.push_back(std::move(listener));
    auto it = std::prev(DestructionListener.end());
    return Ticket([this, it]()
    {
        DestructionListener.erase(it);
    });
}

IEntity::~IEntity()
{
    for(auto &i : DestructionListener)
        i();
}
