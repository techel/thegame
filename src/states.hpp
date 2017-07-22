#pragma once

#include <memory>
#include <vector>

#include <sfml/Graphics/RenderTarget.hpp>

//
// game state interface
//

struct IState
{
	virtual ~IState() = default;
	virtual void tick(float seconds) = 0;
	virtual void render(sf::RenderTarget &r) const = 0;
};

//
// transition interface
//

struct ITransition
{
    virtual ~ITransition() = default;
    virtual void tick(float seconds) = 0;
    virtual void draw(sf::RenderTarget &g, const IState &state) const = 0;
    virtual bool isFinished() const = 0;
};

//
// game states
//

class StateManager
{
public:
    StateManager() = default;

	template<class State, class... Args>
	void setNextState(Args &&...args)
	{
		NextState = std::make_unique<State>(std::forward<Args>(args)...);
	}

    template<class Transition, class... Args>
    void transition(Args &&...args)
    {
        CurrentTransition = std::make_unique<Transition>(std::forward<Args>(args)...);
    }

	void tick(float time, sf::RenderTarget &g);

private:
    std::unique_ptr<IState> CurrentState;
    std::unique_ptr<IState> NextState;
    std::unique_ptr<ITransition> CurrentTransition;

};
