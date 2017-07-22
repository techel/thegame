#pragma once

#include "nonmovable.hpp"
#include "gamewindow.hpp"

class Player;

class PlayerController : nonMovable
{
public:
    PlayerController(GameWindow &input);

    enum class InputMode { Player1, Player2 };

    void setPlayer(Player &p, InputMode mode);
    Player *getPlayer() const { return TargetPlayer; }

private:
    Ticket KeyDownEventTicket, KeyUpEventTicket;

    void keyDown(const sf::Event::KeyEvent &e);
    void keyUp(const sf::Event::KeyEvent &e);

    InputMode Mode;
    Player *TargetPlayer = nullptr;
    Ticket PlayerDestroyTicket;
};
