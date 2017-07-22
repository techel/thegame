#include "camera.hpp"

Ticket Camera::follow(const IEntity *entity)
{
	Target = entity;

	return Ticket([this, entity]()
	{
		if(Target == entity)
			Target = nullptr;
	});
}

void Camera::setVelocity(float velocity)
{
	Velocity = velocity;
}

void Camera::setResolution(const sf::Vector2f &resolution)
{
	View.setSize(resolution);
	View.setCenter(resolution / 2.0f);
}

void Camera::tick(float seconds)
{
	if(Target)
	{
		auto viewpos = View.getCenter();
		View.setCenter(viewpos + (Target->getPosition() - viewpos) * Velocity * seconds);
	}
}
