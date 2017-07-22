#pragma once

#include "states.hpp"

#include <sfml/Graphics/RectangleShape.hpp>

class App;

class WinState : public IState
{
public:
    WinState(App &app);

    void tick(float seconds) override;
    void render(sf::RenderTarget &r) const override;

private:
    sf::RectangleShape GameOverShape;
    sf::View View;
};