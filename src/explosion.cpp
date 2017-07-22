#include "explosion.hpp"

#include "app.hpp"
#include "texmanager.hpp"
#include "map.hpp"

static constexpr float ExplosionSize = 15.0f;

Explosion::Explosion(Map &map, App &app)
{
    Shape.setTexture(&app.textures().get("explosion"));
    Shape.setSize({ ExplosionSize, ExplosionSize });

    Anim.setTexture(*Shape.getTexture(), 8, 15.0f);

    Anim.observeFrameChange([this, &map](bool playing)
    {
        if(playing)
            Shape.setTextureRect(Anim.getTextureRect());
        else
            map.removeEntity(*this);
    });

    Anim.play();

    map.shaker().shake(1.0f, { 0.0f, 1.0f });
}

sf::Vector2f Explosion::getPosition() const
{
    return Shape.getPosition();
}

void Explosion::setPosition(const sf::Vector2f &pos)
{
    Shape.setPosition(pos);
}

void Explosion::tick(float seconds)
{
    Anim.tick(seconds);
}

void Explosion::render(sf::RenderTarget &target) const
{
    target.draw(Shape);
}
