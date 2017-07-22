#pragma once

#include <memory>
#include <vector>
#include <utility>

#include "nonmovable.hpp"
#include "app.hpp"
#include "taskqueue.hpp"
#include "entity.hpp"
#include "camera.hpp"
#include "physics.hpp"
#include "playercontroller.hpp"
#include "background.hpp"
#include "screenshake.hpp"
#include "hud.hpp"

class Map : nonMovable, nonCopyable
{
public:
	Map(App &app);

	IEntity &addEntity(std::unique_ptr<IEntity> entity);

	template<class T, class... Args>
		T &addEntity(Args&&... args)
		{
			auto entity = std::make_unique<T>(std::forward<Args>(args)...);
			return static_cast<T&>(addEntity(std::move(entity)));
		}

	void removeEntity(IEntity &e); //remove is delegated to the 'tick' method

	Camera &camera() { return TheCamera; }
	Physics &physics() { return ThePhysics; }

	PlayerController &player1() { return Player1Controller; }
	PlayerController &player2() { return Player2Controller; }

    Hud &hud1() { return Player1Hud; }
    Hud &hud2() { return Player2Hud; }

    ScreenShaker &shaker() { return Shaker; }

	void tick(float seconds);
	void render(sf::RenderTarget &target) const;

    void generate();

private:
    App *MyApp;

	TaskQueue Deferred;
	Camera TheCamera;
	Physics ThePhysics;

	std::vector<std::unique_ptr<IEntity>> Entities;

	PlayerController Player1Controller, Player2Controller;
    Hud Player1Hud, Player2Hud;

    ScreenShaker Shaker;
    Background TheBackground;

    void computeVerticalSpan();
    float MaxHeight = 0.0f;
    float MaxVertical = 0.0f;
};
