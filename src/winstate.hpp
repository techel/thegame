#pragma once

#include <sfml/Graphics/RectangleShape.hpp>

#include "states.hpp"
#include "ticket.hpp"

class App;
class Map;

class WinState : public IState
{
public:
    WinState(App &app);

    void tick(float seconds) override;
    void render(sf::RenderTarget &r) const override;

private:
    sf::RectangleShape GameOverShape;
    sf::View View;

    Ticket KeyEventTicket;
};