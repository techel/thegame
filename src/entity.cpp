#include "entity.hpp"

Ticket IEntity::observeDestruction(std::function<void()> listener) const
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
    //listeners may change this list when called
    while(!DestructionListener.empty())
    {
        const auto *front = &DestructionListener.front();
        auto l = std::move(*front);
        l();

        if(!DestructionListener.empty() && front == &DestructionListener.front())
            DestructionListener.pop_front();
    }
}
