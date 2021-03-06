#pragma once

#include <list>
#include <functional>

#include <sfml/Graphics/RenderTarget.hpp>
#include <sfml/System/Vector2.hpp>

#include "nonmovable.hpp"
#include "ticket.hpp"

//
// entity interface
//

struct IEntity : nonMovable
{
    virtual ~IEntity();

	virtual sf::Vector2f getPosition() const = 0;
	virtual void setPosition(const sf::Vector2f &pos) = 0;

	virtual void tick(float seconds) = 0;
	virtual void render(sf::RenderTarget &target) const = 0;

    Ticket observeDestruction(std::function<void()> listener) const;

    template<class T>
    T *cast() { return dynamic_cast<T*>(this); }

    template<class T>
    const T *cast() const { return dynamic_cast<const T*>(this); }

private:
    mutable std::list<std::function<void()>> DestructionListener;
};
