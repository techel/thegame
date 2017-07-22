#pragma once

#include <sfml/Graphics/RenderTarget.hpp>
#include <sfml/Graphics/RectangleShape.hpp>

#include "ticket.hpp"

class App;
class Player;

class Hud
{
public:
    Hud();

    void setPlayer(Player &p);

    void tick(float seconds);
    void render(sf::RenderTarget &target) const;

private:
    Player *MyPlayer = nullptr;
    Ticket PlayerTicket;

    sf::RectangleShape Bar;
};