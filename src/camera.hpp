#pragma once

#include <sfml/Graphics/View.hpp>

#include "entity.hpp"
#include "ticket.hpp"
#include "nonmovable.hpp"

class Camera : nonMovable, nonCopyable
{
public:
	Camera() = default;

	//The returned ticket removes the target when destroyed.
	//argument may be nullptr to disable.
	Ticket follow(const IEntity *entity);

	//set velocity the camera is moving towards the target
	void setVelocity(float velocity);

	void setResolution(const sf::Vector2f &resolution);

	const sf::View &getView() const { return View; }

	void tick(float seconds);

private:
	float Velocity = 1.0f;
	const IEntity *Target = nullptr;
	
	sf::View View;
};