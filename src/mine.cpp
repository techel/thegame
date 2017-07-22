#include "mine.hpp"

#include <cmath>

#include "app.hpp"
#include "texmanager.hpp"
#include "map.hpp"
#include "platform.hpp"
#include "explosion.hpp"
#include "soundmanager.hpp"

static constexpr float MineSize = 1.5f;
static constexpr float SensorsSize = 0.2f;
static constexpr float TossVelocity0 = 32.0f;
static constexpr float AngularFrequency = 2.0f;

Mine::Mine(Map &map, App &app) : MyApp(&app), MyMap(&map)
{
    Shape.setTexture(&app.textures().get("mine"));
    Shape.setSize({ MineSize, MineSize });
    Shape.setOrigin({ MineSize / 2, MineSize / 2 });

    Anim.setTexture(*Shape.getTexture(), 2, 3.0f, true);

    Anim.observeFrameChange([this, &map](bool)
    {
        Shape.setTextureRect(Anim.getTextureRect());
    });

    Anim.play();

    Box::Predefinitions def;
    def.MainFix.filter.categoryBits = Filter::Interactable;
    def.MainFix.filter.maskBits = Filter::Wall;
    def.MainFix.friction = 1.0f;
    def.MainFix.density = 1.0f;
    def.LeftSensor = def.RightSensor = def.TopSensor = def.BottomSensor = def.MainFix;

    b2CircleShape circle;
    circle.m_p = { MineSize / 2, MineSize / 2 };
    circle.m_radius = MineSize / 2.0f;
    def.MainFix.shape = &circle;

    def.Body.fixedRotation = true;
    def.Body.type = b2_dynamicBody;
    def.Body.userData = static_cast<IEntity*>(this);

    Body = std::make_unique<Box>(map.physics(), sf::Vector2f(MineSize, MineSize), SensorsSize, def);

    Body->observeCollision([this](Box&, IEntity &b, Box::Direction dir, Box::Collision c)
    {
        if(c == Box::Collision::Touch)
        {
            auto *plat = dynamic_cast<Platform*>(&b);
            if(plat)
            {
                if(dir == Box::Direction::Bottom)
                    Shape.setRotation(0.0f);
                else if(dir == Box::Direction::Right)
                    Shape.setRotation(90.0f);
                else if(dir == Box::Direction::Top)
                    Shape.setRotation(180.0f);
                else if(dir == Box::Direction::Left)
                    Shape.setRotation(270.0f);

                CurrentState = State::Stick;

                PlatformTicket = plat->observeDestruction([this]()
                {
                    DestPlatform = nullptr;
                    PlatformTicket.release();
                });

                DestPlatform = plat;
            }
        }
    });
}

sf::Vector2f Mine::getPosition() const
{
    auto pos = Body->body().GetPosition();
    return{ pos.x, pos.y };
}

void Mine::setPosition(const sf::Vector2f &pos)
{
    Body->body().SetTransform({ pos.x, pos.y }, 0.0f);
}	

void Mine::toss(const sf::Vector2f &dir)
{
    StickTime = 0.0f;

    auto normalized = dir / std::sqrt(dir.x*dir.x + dir.y*dir.y);
    auto impulse = dir * TossVelocity0 * Body->body().GetMass();

    Body->body().ApplyLinearImpulse({ impulse.x, impulse.y }, { MineSize / 2, MineSize / 2 }, false);

    CurrentState = State::Toss;
}

void Mine::tick(float seconds)
{
    Anim.tick(seconds);

    auto pos = Body->body().GetPosition();
    Shape.setPosition({ pos.x + MineSize / 2, pos.y + MineSize / 2 });

    if(CurrentState == State::Toss)
        Shape.rotate(360.0f * AngularFrequency * seconds);

    StickTime += seconds;
    if(CurrentState != State::None && StickTime >= 3.0f)
    {
        if(DestPlatform)
            DestPlatform->explode();

        auto &ex = MyMap->addEntity<Explosion>(*MyMap, *MyApp);
        ex.setPosition(getPosition());

        MyApp->sound().playSound("boom");

        CurrentState = State::None;

        MyMap->removeEntity(*this);
    }
}

void Mine::render(sf::RenderTarget &target) const
{
    target.draw(Shape);
}
