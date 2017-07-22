#pragma once

#include <functional>
#include <list>
#include <map>

#include <sfml/Graphics/RenderWindow.hpp>
#include <sfml/Window/Event.hpp>
#include <sfml/System/Vector2.hpp>

#include "nonmovable.hpp"
#include "taskqueue.hpp"
#include "ticket.hpp"

class GameWindow : nonMovable, nonCopyable
{
public:
	GameWindow();

	using EventListener = std::function<void(const sf::Event&)>;

	//registers an event listener. The returned ticket will automatically unregister it on destruction.
	Ticket observeEvents(sf::Event::EventType type, EventListener listener);

	//returns true when window has been closed
	bool tick();

	//retrieve best fitting 16/9 viewport
	sf::FloatRect getViewport() const { return Viewport; }

	//returns the render target to draw to
	sf::RenderTarget &target() { return Window; }

private:
	sf::RenderWindow Window;
	std::map<sf::Event::EventType, std::list<EventListener>> EventListeners;

	sf::FloatRect Viewport;
    void renewViewport();

    TaskQueue Deferred;
};