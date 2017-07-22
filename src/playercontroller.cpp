#include "playercontroller.hpp"

#include "player.hpp"

static constexpr auto Player1Jump = sf::Keyboard::Key::Up;
static constexpr auto Player1Left = sf::Keyboard::Key::Left;
static constexpr auto Player1Right = sf::Keyboard::Key::Right;
static constexpr auto Player1Action = sf::Keyboard::Key::Down;

static constexpr auto Player2Jump = sf::Keyboard::Key::W;
static constexpr auto Player2Left = sf::Keyboard::Key::A;
static constexpr auto Player2Right = sf::Keyboard::Key::D;
static constexpr auto Player2Action = sf::Keyboard::Key::S;

PlayerController::PlayerController(GameWindow &input)
{
    KeyDownEventTicket = input.observeEvents(sf::Event::EventType::KeyPressed, [this](const sf::Event &e)
    {
        keyDown(e.key);
    });

    KeyUpEventTicket = input.observeEvents(sf::Event::EventType::KeyReleased, [this](const sf::Event &e)
    {
        keyUp(e.key);
    });
}

void PlayerController::setPlayer(Player &p, InputMode mode)
{
    p.observeDestruction([this, &p]()
    {
        if(TargetPlayer == &p)
            TargetPlayer = nullptr;
    });

    TargetPlayer = &p;
    Mode = mode;
}

void PlayerController::keyDown(const sf::Event::KeyEvent &e)
{
    if(TargetPlayer)
    {
        if(Mode == InputMode::Player1)
        {
            if(e.code == Player1Jump)
                TargetPlayer->jump();

            if(e.code == Player1Left)
                TargetPlayer->walk(Player::Walk::Left);

            if(e.code == Player1Right)
                TargetPlayer->walk(Player::Walk::Right);

            if(e.code == Player1Action)
                TargetPlayer->action();
        }
        else if(Mode == InputMode::Player2)
        {
            if(e.code == Player2Jump)
                TargetPlayer->jump();

            if(e.code == Player2Left)
                TargetPlayer->walk(Player::Walk::Left);

            if(e.code == Player2Right)
                TargetPlayer->walk(Player::Walk::Right);

            if(e.code == Player2Action)
                TargetPlayer->action();
        }
    }
}

void PlayerController::keyUp(const sf::Event::KeyEvent &e)
{
    if(TargetPlayer)
    {
        if(Mode == InputMode::Player1)
        {
            if(e.code == Player1Left || e.code == Player1Right)
                TargetPlayer->walk(Player::Walk::None);
        }
        else if(Mode == InputMode::Player2)
        {
            if(e.code == Player2Left || e.code == Player2Right)
                TargetPlayer->walk(Player::Walk::None);
        }
    }
}
