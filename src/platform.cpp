#include "platform.hpp"

#include "texmanager.hpp"
#include "app.hpp"
#include "map.hpp"
#include "explosion.hpp"

static constexpr float PlatformHeight = 1.3f;

Platform::Platform(Map &map, App &app, float width) : MyMap(&map), MyApp(&app)
{
    Sprite.setTexture(&app.textures().get("platform"));
    Sprite.setSize({ width, PlatformHeight });

    const b2Vec2 hsize = { width / 2.0f, PlatformHeight / 2.0f };

    b2BodyDef bodydef;
    bodydef.type = b2_staticBody;
    bodydef.userData = static_cast<IEntity*>(this);

    Body.reset(map.physics().world().CreateBody(&bodydef));

    b2PolygonShape shape;
    shape.SetAsBox(hsize.x, hsize.y, hsize, 0.0f);

    b2FixtureDef fixdef;
    fixdef.filter.categoryBits = Filter::Wall;
    fixdef.filter.maskBits = Filter::All;
    fixdef.friction = 1.0f;
    fixdef.shape = &shape;

    Body->CreateFixture(&fixdef);
}

sf::Vector2f Platform::getPosition() const
{
    auto pos = Body->GetPosition();
    return { pos.x, pos.y };
}

void Platform::setPosition(const sf::Vector2f & pos)
{
    Body->SetTransform({ pos.x, pos.y }, 0.0f);
}

void Platform::explode()
{
    MyMap->removeEntity(*this);
}

void Platform::tick(float seconds)
{
    auto pos = Body->GetPosition();
    Sprite.setPosition({ pos.x, pos.y });
}

void Platform::render(sf::RenderTarget &target) const
{
    target.draw(Sprite);
}
