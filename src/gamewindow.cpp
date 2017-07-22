#include "gamewindow.hpp"

#include <utility>
#include <iterator>

#include <sfml/Graphics.hpp>

constexpr unsigned int WindowWidth = 900;
constexpr unsigned int WindowHeight = 600;

GameWindow::GameWindow()
{
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();

	mode.width = WindowWidth;
	mode.height = WindowHeight;

	Window.create(mode, "thegame", sf::Style::Default);

	renewViewport();
}

Ticket GameWindow::observeEvents(sf::Event::EventType type, EventListener listener)
{
	auto &typelist = EventListeners[type];
	typelist.push_back(std::move(listener));

	auto it = std::prev(typelist.end());

	return Ticket([it, &typelist]()
	{
		typelist.erase(it);
	});
}

bool GameWindow::tick()
{
	Window.display();

	sf::Event event;
	if(Window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			return false;

		if(event.type == sf::Event::Resized)
			renewViewport();
		
		auto it = EventListeners.find(event.type);
		if(it != EventListeners.end())
		{
			for(auto &l : it->second)
				l(event);
		}
	}

    Window.clear();

	return true;
}

void GameWindow::renewViewport()
{
	auto s = Window.getSize();

	sf::Vector2u off, siz;
	if(s.x * 9 / 16 > s.y)
	{
		auto newwidth = s.y * 16 / 9;
		off.x = (s.x - newwidth) / 2;
		off.y = 0;
		siz.x = newwidth;
		siz.y = s.y;
	}
	else if(s.y * 16 / 9 > s.x)
	{
		auto newheigth = s.x * 9 / 16;
		off.y = (s.y - newheigth) / 2;
		off.x = 0;
		siz.x = s.x;
		siz.y = newheigth;
	}
	else
	{
		off = { 0, 0 };
		siz = s;
	}

	Viewport.left = off.x / static_cast<float>(s.x);
	Viewport.top = off.y / static_cast<float>(s.y);
	Viewport.width = siz.x / static_cast<float>(s.x);
	Viewport.height = siz.y / static_cast<float>(s.y);

	sf::View view;
	view.setViewport(Viewport);
	Window.setView(view);
}
