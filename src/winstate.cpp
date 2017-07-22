#include "winstate.hpp"

#include "gamewindow.hpp"
#include "texmanager.hpp"
#include "app.hpp"
#include "playstate.hpp"
#include "soundmanager.hpp"

static constexpr float ViewSize = 10.0f;

WinState::WinState(App &app)
{
    GameOverShape.setTexture(&app.textures().get("gameover"));
    GameOverShape.setSize({ ViewSize, ViewSize });

    View.setSize({ ViewSize, ViewSize });
    View.setCenter({ ViewSize / 2.0f, ViewSize / 2.0f });

    KeyEventTicket = app.window().observeEvents(sf::Event::EventType::KeyReleased, [this, &app](const sf::Event&)
    {
        app.states().setNextState<PlayState>(app);
    });

    app.sound().stopMusic();
    app.sound().playSound("whistle");
}

void WinState::tick(float seconds)
{
}

void WinState::render(sf::RenderTarget &target) const
{
    auto view = View;
    view.setViewport(target.getView().getViewport());
    target.setView(view);

    target.draw(GameOverShape);
}
