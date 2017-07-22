#include "camera.hpp"

#include <algorithm>

void Camera::follow(std::vector<const IEntity*> entities)
{
	for(const auto &e : entities)
    {
        e->observeDestruction([this]()
        {
            Targets.clear();
        });
    }

    Targets = std::move(entities);
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
	if(!Targets.empty())
	{
        sf::Vector2f sum; //compute average position
        for(const auto &e : Targets)
            sum += e->getPosition();

        auto target = sum / static_cast<float>(Targets.size());

		auto viewpos = View.getCenter();
		View.setCenter(viewpos + (target - viewpos) * Velocity * seconds);
	}
}
