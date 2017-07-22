#include "states.hpp"

#include <cassert>
#include <thread>
#include <chrono>

void StateManager::tick(float time, sf::RenderTarget &g)
{
    if(NextState)
        CurrentState = std::move(NextState);

	if(CurrentState)
	{
        CurrentState->tick(time);
        if(CurrentTransition)
        {
            CurrentTransition->tick(time);
            CurrentTransition->draw(g, *CurrentState);
            if(CurrentTransition->isFinished())
                CurrentTransition = nullptr;
        }
        else
            CurrentState->render(g);
	}

    if(CurrentTransition && CurrentTransition->isFinished())
        CurrentTransition.reset();
}
