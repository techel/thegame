#include "map.hpp"

#include <cassert>
#include <utility>
#include <algorithm>

#include "viewguard.hpp"

Map::Map(App &app) : Player1Controller(app.window()), Player2Controller(app.window())
{
	TheCamera.setResolution({ 100.0f, 100.0f * 9.0f / 16.0f });
    TheCamera.setVelocity(5.0f);
}

IEntity &Map::addEntity(std::unique_ptr<IEntity> entity)
{
	assert(entity);

	auto &ref = *entity.get();
	Entities.push_back(std::move(entity));
	return ref;
}

void Map::removeEntity(IEntity &e)
{
	Deferred.enqueue([this, &e]() mutable
	{
	    auto it = std::find_if(Entities.begin(), Entities.end(), [&e](const auto &entityptr)
	    {
		    return &e == entityptr.get();
	    });

	    assert(it != Entities.end());
        Entities.erase(it);
	});
}

void Map::tick(float seconds)
{
    for(auto &e : Entities)
        e->tick(seconds);

	Deferred.dispatchAll();

	TheCamera.tick(seconds);
    ThePhysics.tick(seconds);
}

void Map::render(sf::RenderTarget &target) const
{
	auto view = TheCamera.getView(); //preserve viewport
	view.setViewport(target.getView().getViewport());
	target.setView(view);

	for(const auto &e : Entities)
		e->render(target);
}
