#include "winstate.hpp"

#include "texmanager.hpp"
#include "app.hpp"

static constexpr float ViewSize = 10.0f;

WinState::WinState(App &app)
{
    GameOverShape.setTexture(&app.textures().get("gameover"));
    GameOverShape.setSize({ ViewSize, ViewSize });

}

void WinState::tick(float seconds)
{
}

void WinState::render(sf::RenderTarget & r) const
{
}
