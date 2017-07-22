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
        sf::Vector2f heighest = Targets[0]->getPosition();

        for(const auto &e : Targets)
        {
            auto pos = e->getPosition();
            sum += pos;
            if(pos.y < heighest.y)
                heighest = pos;
        }

        auto target = (sum + sum + heighest) / static_cast<float>(Targets.size() * 2 + 1);

		auto viewpos = View.getCenter();
		View.setCenter(viewpos + (target - viewpos) * Velocity * seconds);
	}
}
