#pragma once

#include "app.hpp"
#include "map.hpp"
#include "states.hpp"

class PlayState : public IState
{
public:
	PlayState(App &app);

	void tick(float seconds) override;
	void render(sf::RenderTarget & r) const override;

private:
	Map TheMap;
};