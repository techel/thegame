#pragma once

#include <memory>
#include <vector>
#include <utility>

#include "taskqueue.hpp"
#include "entity.hpp"
#include "camera.hpp"
#include "nonmovable.hpp"

class Map : nonMovable, nonCopyable
{
public:
	Map();

	IEntity &addEntity(std::unique_ptr<IEntity> entity);

	template<class T, class... Args>
	T &addEntity(Args&&... args)
	{
		auto entity = std::make_unique<T>(std::forward<Args>(args)...);
		return static_cast<T&>(addEntity(std::move(entity)));
	}

	void removeEntity(IEntity &e); //remove is delegated to the 'tick' method

	Camera &camera() { return TheCamera; }

	void tick(float seconds);
	void render(sf::RenderTarget &target) const;

private:
	std::vector<std::unique_ptr<IEntity>> Entities;
	TaskQueue Deferred;

	Camera TheCamera;
};
