#include "map.hpp"

#include <cassert>
#include <utility>
#include <algorithm>

#include "viewguard.hpp"

Map::Map(App &app) : Player1Controller(app.window()), Player2Controller(app.window()), TheBackground(app)
{
	TheCamera.setResolution({ 100.0f, 100.0f * 9.0f / 16.0f });
    TheCamera.setVelocity(5.0f);

    Shaker.setParameters(7.0f, 3.0f, 1.0f);
}

IEntity &Map::addEntity(std::unique_ptr<IEntity> entity)
{
	assert(entity);

	auto &ref = *entity.get();

    Deferred.enqueue([this, entity = std::move(entity)]() mutable
    {
        Entities.push_back(std::move(entity));
    });

	return ref;
}

void Map::removeEntity(IEntity &e)
{
	Deferred.enqueue([this, e = &e]() mutable
	{
	    auto it = std::find_if(Entities.begin(), Entities.end(), [&e](const auto &entityptr)
	    {
		    return e == entityptr.get();
	    });

        if(it != Entities.end())
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
    Shaker.tick(seconds);
}

void Map::render(sf::RenderTarget &target) const
{
    {
        TheBackground.render(target);
    }
    {
        auto view = TheCamera.getView();
        view.move(Shaker.getOffset());
        view.setViewport(target.getView().getViewport());

        target.setView(view);

        for(const auto &e : Entities)
            e->render(target);
    }
}
