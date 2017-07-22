#include "map.hpp"

#include <cassert>
#include <utility>
#include <algorithm>
#include <random>

#include "viewguard.hpp"
#include "app.hpp"
#include "platform.hpp"

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

void Map::generate(App &app)
{
	int floor_count = 20;
	float floor_width = 20.0f;
	float floor_position_y = 20.0f;

	int platform_count = 30;
	float plat_width = 20.0f;
	int height = 20;
	float padding = 6.0f;

	int preset_count = 5;
	int preset[][preset_count] = {
		{0,1,1,0,1},
		{0,1,1,1,0},
		{1,1,0,0,1},
		{1,1,0,1,0},
		{1,0,1,1,0}
	};

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distributionP(0, 4);
	std::uniform_int_distribution<int> distributionF(2, 4);

	auto rndF = std::bind(distributionF, generator);
	auto rndP = std::bind(distributionP, generator);	

	//Bottom
	for(int i = 0; i < floor_count; i++)
	{
		auto &plat = this->addEntity<Platform>(*this, app, floor_width);
		plat.setPosition({ i * floor_width - floor_count * floor_width / 2, floor_position_y });
	}

	// Platforms
	for(int i = 0; i < height; i++)
	{	
		int index = rndP();
		platform_count = rndF();
		for(int j = 0; j < preset_count; j++)
		{
			// Empy in preset -> continue
			if(preset[index][j] < 1) {j++; continue;}

			auto &plat = this->addEntity<Platform>(*this, app, plat_width);
			plat.setPosition({ j * -(plat_width + padding) -(i%2 * 10.0f), i * -8.0f + floor_position_y});
		}
	}
}
