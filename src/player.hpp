#pragma once

#include <sfml/Graphics.hpp>
#include <functional>
#include <sfml/Graphics/RectangleShape.hpp>

#include "entity.hpp"
#include "physbox.hpp"

class Map;
class App;

class Player : public IEntity
{
	public:
		Player(Map &map, App &app);

		sf::Vector2f getPosition() const override;
		void setPosition(const sf::Vector2f &pos) override;

		enum class Face { Left, Right };
		Face getFace() const { return FaceDirection; }

		enum class Walk { Left, Right, None };
		void walk(Walk dir);

		void jump();
		void action();

        sf::Vector2f getSize() const;

        unsigned int getLives() const { return Lives; }
        constexpr static unsigned int getMaxLives() { return 3; }
        void takeDamage(unsigned int lives);

		void tick(float seconds) override;
		void render(sf::RenderTarget &target) const override;

	private:
		sf::RectangleShape Sprite;
        Map *MyMap;
        App *MyApp;

	    std::unique_ptr<Box> Body;

	    Face FaceDirection = Face::Right;

	    bool Walking = false;
	    float DestWalkVelocity = 0.0f;
	    float WalkAnimation = 0.0f;

        float MineCooldown = 0.0f;

        unsigned int Lives = getMaxLives();
};
