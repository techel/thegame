#include "map.hpp"

#include <cassert>
#include <utility>
#include <algorithm>
#include <random>

#include "platform.hpp"
#include "player.hpp"
#include "plop.hpp"
#include "winstate.hpp"
#include "soundmanager.hpp"

Map::Map(App &app) : MyApp(&app), Player1Controller(app.window()), Player2Controller(app.window()), TheBackground(app)
{
	TheCamera.setResolution({ 100.0f, 100.0f * 9.0f / 16.0f });
    TheCamera.setVelocity(3.0f);

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

    auto camview = TheCamera.getView();
    auto viewsize = camview.getSize();
    auto bottom = camview.getCenter().y + viewsize.y / 2.0f;

    Player *p1 = player1().getPlayer();
    Player *p2 = player2().getPlayer();

    if(p1 && p2)
    {
        auto pos1 = p1->getPosition();
        auto pos2 = p2->getPosition();

        if(pos1.y > viewsize.y / 2 && pos2.y > viewsize.y / 2)
        {
            MyApp->states().setNextState<WinState>(*MyApp);
        }
        else
        {
            auto addplop = [&](const sf::Vector2f &pos)
            {
                auto &plop = addEntity<Plop>(*this, *MyApp);
                plop.setPosition(pos);
                MyApp->sound().playSound("warp");
            };

            if(pos1.y > bottom)
            {
                p1->setPosition(pos2);
                addplop(pos2);
            }
            if(pos2.y > bottom)
            {
                p2->setPosition(pos1);
                addplop(pos1);
            }
        }
    }
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

void Map::generate()
{
    int floor_count = 20;
    float floor_width = 20.0f;
    float floor_position_y = 20.0f;

    int platform_count = 30;
    float plat_width = 20.0f;
    int height = 20;
    float padding = 6.0f;

    constexpr size_t preset_count = 5;
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
        auto &plat = this->addEntity<Platform>(*this, *MyApp, floor_width);
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

            auto &plat = this->addEntity<Platform>(*this, *MyApp, plat_width);
            plat.setPosition({ j * -(plat_width + padding) -(i%2 * 10.0f), i * -8.0f + floor_position_y});
        }
    }
}
