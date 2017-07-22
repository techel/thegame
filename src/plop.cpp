#include "plop.hpp"

#include "app.hpp"
#include "texmanager.hpp"
#include "map.hpp"

static constexpr float PlopSize = 8.0f;

Plop::Plop(Map &map, App &app)
{
    Shape.setTexture(&app.textures().get("plop"));
    Shape.setSize({ PlopSize, PlopSize });

    Anim.setTexture(*Shape.getTexture(), 8, 15.0f);

    Anim.observeFrameChange([this, &map](bool playing)
    {
        if(playing)
            Shape.setTextureRect(Anim.getTextureRect());
        else
            map.removeEntity(*this);
    });

    Anim.play();
}

sf::Vector2f Plop::getPosition() const
{
    return Shape.getPosition();
}

void Plop::setPosition(const sf::Vector2f &pos)
{
    Shape.setPosition(pos);
}

void Plop::tick(float seconds)
{
    Anim.tick(seconds);
}

void Plop::render(sf::RenderTarget &target) const
{
    target.draw(Shape);
}
