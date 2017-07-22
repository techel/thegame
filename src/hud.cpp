#include "hud.hpp"

#include "player.hpp"

static constexpr float BarHeight = 0.3f;
static constexpr float BarWidth = 6.0f;

Hud::Hud()
{
    Bar.setFillColor({200, 0, 0, 100});
    Bar.setSize({ BarWidth, BarHeight });
}

void Hud::setPlayer(Player &p)
{
    PlayerTicket = p.observeDestruction([this]()
    {
        MyPlayer = nullptr;
        PlayerTicket.release();
    });

    MyPlayer = &p;
}

void Hud::tick(float)
{
    if(MyPlayer)
    {
        Bar.setPosition(MyPlayer->getPosition() - sf::Vector2f(0.0f, 1.0f));
        Bar.setScale({ static_cast<float>(MyPlayer->getLives()) / MyPlayer->getMaxLives(), 1.0f });
    }
}

void Hud::render(sf::RenderTarget &target) const
{
    if(MyPlayer)
        target.draw(Bar);
}
