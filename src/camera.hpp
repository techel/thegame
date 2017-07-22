#pragma once

#include <vector>
#include <sfml/Graphics/View.hpp>

#include "entity.hpp"
#include "ticket.hpp"
#include "nonmovable.hpp"

class Camera : nonMovable, nonCopyable
{
public:
	Camera() = default;

	void follow(std::vector<const IEntity*> entities);

	//set velocity the camera is moving towards the target
	void setVelocity(float velocity);

	void setResolution(const sf::Vector2f &resolution);

	const sf::View &getView() const { return View; }

	void tick(float seconds);

private:
	float Velocity = 1.0f;
    std::vector<const IEntity*> Targets;
	
	sf::View View;
};